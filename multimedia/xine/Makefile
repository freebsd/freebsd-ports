# $FreeBSD$

PORTNAME=	xine
PORTVERSION=	0.99.8
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-ui/${PORTVERSION}
DISTNAME=	${PORTNAME}-ui-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 multimedia player

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libxine.so:${PORTSDIR}/multimedia/libxine

USE_XZ=		yes
USES=		desktop-file-utils gmake iconv pkgconfig readline \
		shared-mime-info
USE_XORG=	x11 xext xinerama xscrnsaver xt xtst xv xxf86vm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vdr-keys \
		--disable-nvtvsimple \
		--disable-rpath
MAKE_ENV=	V=1
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/xine-ui
XINE_PLUGINSDIR=	lib/xine/plugins/2.3

OPTIONS_DEFINE=		AALIB CACA CURL DOCS LIRC NLS XFT
OPTIONS_DEFAULT=	CURL XFT
OPTIONS_DEFINE_i386=	WIN32_CODECS
OPTIONS_DEFAULT_i386=	WIN32_CODECS
OPTIONS_SUB=		yes

AALIB_LIB_DEPENDS=	libaa.so:${PORTSDIR}/graphics/aalib
AALIB_CONFIGURE_WITH=	aalib
CACA_LIB_DEPENDS=	libcaca.so:${PORTSDIR}/graphics/libcaca
CACA_RUN_DEPENDS=	${LOCALBASE}/${XINE_PLUGINSDIR}/xineplug_vo_out_caca.so:${PORTSDIR}/multimedia/libxine
CACA_CONFIGURE_WITH=	caca
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_WITH=	curl
LIRC_LIB_DEPENDS=	liblirc_client.so:${PORTSDIR}/comms/lirc
LIRC_CONFIGURE_ENV=	LIRC_CFLAGS="-I${LOCALBASE}/include" \
			LIRC_LIBS="-L${LOCALBASE}/libs -llirc_client"
LIRC_CONFIGURE_ENABLE=	lirc
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
WIN32_CODECS_DESC=	Enable win32 codecs
WIN32_CODECS_RUN_DEPENDS=\
			win32-codecs>0:${PORTSDIR}/multimedia/win32-codecs
XFT_USE=		XORG=xft
XFT_CONFIGURE_ENABLE=	xft

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000052
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

.if empty(ICONV_CONFIGURE_ARG)
CONFIGURE_ARGS+=	--without-libiconv-prefix
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|<string.h>|<strings.h>|' ${WRKSRC}/src/aaui/main.c

.include <bsd.port.mk>
