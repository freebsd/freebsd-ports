# $FreeBSD$

PORTNAME=	xine
PORTVERSION=	0.99.12
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-ui/${PORTVERSION}
DISTNAME=	${PORTNAME}-ui-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 multimedia player

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libxine.so:multimedia/libxine

USES=		desktop-file-utils gmake gnome iconv jpeg localbase pkgconfig \
		readline shared-mime-info tar:xz xorg
USE_XORG=	x11 xext xinerama xscrnsaver xt xtst xv xxf86vm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vdr-keys \
		--disable-nvtvsimple \
		--disable-rpath
MAKE_ENV=	V=1
INSTALLS_ICONS=	yes

LLD_UNSAFE=	yes	# lld disallows preemption of protected visibility syms

DOCSDIR=	${PREFIX}/share/doc/xine-ui

OPTIONS_DEFINE=		AALIB CACA CURL DOCS LIRC NLS XFT
OPTIONS_DEFAULT=	CURL XFT
OPTIONS_DEFINE_i386=	WIN32_CODECS
OPTIONS_SUB=		yes

AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_CONFIGURE_WITH=	aalib
CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_RUN_DEPENDS=	${LOCALBASE}/${XINE_PLUGINSDIR}/xineplug_vo_out_caca.so:multimedia/libxine
CACA_CONFIGURE_WITH=	caca
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENV=	LIRC_CFLAGS="-I${LOCALBASE}/include" \
			LIRC_LIBS="-L${LOCALBASE}/libs -llirc_client"
LIRC_CONFIGURE_ENABLE=	lirc
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
WIN32_CODECS_DESC=	Enable win32 codecs
WIN32_CODECS_RUN_DEPENDS=\
			win32-codecs>0:multimedia/win32-codecs
XFT_USE=		XORG=xft
XFT_CONFIGURE_ENABLE=	xft

XINE_PLUGINSDIR=	lib/xine/plugins/2.7

post-patch:
	@${REINPLACE_CMD} -e \
		's/font = */font = *-*-bold-o-*-*-12-*-*-*-*-*-*-*/g' \
		${WRKSRC}/src/xitk/skins/xinetic/skinconfig
	@${REINPLACE_CMD} -e \
		's|<string.h>|<strings.h>|' ${WRKSRC}/src/aaui/main.c
	@${REINPLACE_CMD} -e \
		's|<\(readline.h\)>|<readline/\1>| ; \
		 s|<\(history.h\)>|<readline/\1>|' ${WRKSRC}/src/xitk/network.c

.include <bsd.port.mk>
