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

USE_PKGCONFIG=	build
USE_GNOME=	glib20 gnomehack intlhack libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/^GMSGFMT = @GMSGFMT@/GMSGFMT = msgfmt/' ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/libqalculate.pc.in

.include <bsd.port.mk>
