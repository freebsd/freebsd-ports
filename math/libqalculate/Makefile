# Created by: Sergey Akifyev <asa@agava.com>
# $FreeBSD$

PORTNAME=	libqalculate
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/qalculate/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (backend library)

LIB_DEPENDS=	cln:${PORTSDIR}/math/cln

USES=		pkgconfig
USE_GNOME=	glib20 gnomehack intlhack libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's/^GMSGFMT = @GMSGFMT@/GMSGFMT = msgfmt/' ${WRKSRC}/po/Makefile.in.in
.else
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|po ||g' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/libqalculate.pc.in

.include <bsd.port.mk>
