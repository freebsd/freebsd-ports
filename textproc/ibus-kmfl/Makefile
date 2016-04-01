# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	ibus-kmfl
PORTVERSION=	1.0.3
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/${PORTNAME}/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL IMEngine for IBus framework

LIB_DEPENDS=	libibus-1.0.so:textproc/ibus \
		libkmfl.so:textproc/libkmfl \
		libkmflcomp.so:textproc/kmflcomp
RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

USES=		pkgconfig gmake
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${CP} ${WRKSRC}/icons/default.png ${WRKSRC}/icons/default-kmfl.png
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' \
		${WRKSRC}/src/kmflutil.c ${WRKSRC}/src/kmfl.xml.in.in
	@${REINPLACE_CMD} -e 's|default\.png|default-kmfl.png|g' \
		${WRKSRC}/src/kmflutil.c ${WRKSRC}/icons/Makefile.in

.include <bsd.port.mk>
