PORTNAME=	x11vnc
PORTVERSION=	0.9.17
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	VNC server for use with real X displays
WWW=		https://github.com/LibVNC/x11vnc

LICENSE=	GPLv2

LIB_DEPENDS=	libvncserver.so:net/libvncserver \
		libdrm.so:graphics/libdrm

USES=		cpe iconv pkgconfig jpeg ssl gmake autoreconf xorg
USE_XORG=	xcb xau xdmcp ice xcb xorgproto x11 xext xtst xinerama \
		xrandr xfixes xdamage xcomposite xi xcursor xrender
# Sets LDFLAGS and adds to CONFIGURE_ENV, therefore we set LDFLAGS
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libdrm
USE_GITHUB=	yes
GH_ACCOUNT=	LibVNC

CPE_VENDOR=	x11vnc_project

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	NLS AVAHI DOCS
OPTIONS_DEFAULT=AVAHI
NO_OPTIONS_SORT=yes
NLS_USES=	gettext
AVAHI_LIB_DEPENDS=	libavahi-common.so:net/avahi-app
AVAHI_CONFIGURE_OFF=	--without-avahi

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
