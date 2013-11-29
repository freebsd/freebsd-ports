# $FreeBSD$

PORTNAME=	xine
PORTVERSION=	0.99.7
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-ui/${PORTVERSION}
DISTNAME=	${PORTNAME}-ui-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 multimedia player

LICENSE=	GPLv2

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libxine.so:${PORTSDIR}/multimedia/libxine

USE_XZ=		yes
USE_XORG=	x11 xext xinerama xscrnsaver xt xtst xv xxf86vm
USES=		desktop-file-utils gmake pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vdr-keys \
		--disable-nvtvsimple
MAKE_ENV=	V=1
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/xine-ui
XINE_PLUGINSDIR=	lib/xine/plugins/2.3

OPTIONS_DEFINE=	CACA AALIB LIRC CURL NLS XFT DOCS
OPTIONS_DEFAULT=	CURL XFT
OPTIONS_DEFINE_i386=	WIN32_CODECS
OPTIONS_DEFAULT_i386=	WIN32_CODECS
OPTIONS_SUB=	yes

WIN32_CODECS_DESC=	Enable win32 codecs
WIN32_CODECS_RUN_DEPENDS=	win32-codecs>=0:${PORTSDIR}/multimedia/win32-codecs

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

XFT_USE=	XORG=xft
XFT_CONFIGURE_OFF=	--disable-xft

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_OFF=	--without-curl

LIRC_LIB_DEPENDS=	liblirc_client.so:${PORTSDIR}/comms/lirc
LIRC_CONFIGURE_ENV=		LIRC_CFLAGS="-I${LOCALBASE}/include" \
			LIRC_LIBS="-L${LOCALBASE}/libs -llirc_client"
LIRC_CONFIGURE_ENABLE=	lirc

CACA_LIB_DEPENDS=	libcaca.so:${PORTSDIR}/graphics/libcaca
CACA_RUN_DEPENDS=	${LOCALBASE}/${XINE_PLUGINSDIR}/xineplug_vo_out_caca.so
CACA_CONFIGURE_OFF=	--without-caca

AALIB_LIB_DEPENDS=	libaa.so:${PORTSDIR}/graphics/aalib
AALIB_CONFIGURE_ON=	--with-aalib
AALIB_CONFIGURE_OFF=	--without-aalib --disable-aalibtest

post-patch:
	@${REINPLACE_CMD} -e \
		'/THREAD_LIBS/s|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<string.h>|<strings.h>|' ${WRKSRC}/src/aaui/main.c
.for file in doc/Makefile.in src/xitk/xine-toolkit/Makefile.in
	@${REINPLACE_CMD} -e \
		's|: install-docsDATA|:|' ${WRKSRC}/${file}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/xitk
	${INSTALL_DATA} ${WRKSRC}/src/xitk/xine-toolkit/README ${STAGEDIR}${PREFIX}/share/doc/xitk

.include <bsd.port.mk>
