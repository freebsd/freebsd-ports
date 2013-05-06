# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	ibus-kmfl
PORTVERSION=	1.0.3
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/${PORTNAME}/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL IMEngine for IBus framework

LIB_DEPENDS=	ibus-1.0:${PORTSDIR}/textproc/ibus \
		kmfl.0:${PORTSDIR}/textproc/libkmfl \
		kmflcomp.0:${PORTSDIR}/textproc/kmflcomp
RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

USES=		pkgconfig
USE_GNOME=	glib20

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
