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

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
# Please update libxine PLUGINSDIR as well (see below)
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		xine:${PORTSDIR}/multimedia/libxine
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

OPTIONS_DEFINE=	CACA AALIB LIRC CURL NLS XFT DOCS
OPTIONS_DEFAULT=	CURL XFT
OPTIONS_DEFINE_i386=	WIN32_CODECS
OPTIONS_DEFAULT_i386=	WIN32_CODECS

WIN32_CODECS_DESC=	Enable win32 codecs

USE_XZ=		yes
USE_XORG=	x11 xext xinerama xscrnsaver xt xtst xv xxf86vm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vdr-keys \
		--disable-nvtvsimple
MAKE_ENV=	V=1
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MANLANG=	"" de es fr pl
MAN1_EN=	aaxine.1 xine-bugreport.1 xine-check.1 xine-remote.1 xine.1
MAN1_DE=	${MAN1_EN}
MAN1_ES=	${MAN1_EN}
MAN1_FR=	xine.1
MAN1_PL=	aaxine.1 xine-remote.1 xine.1

DOCSDIR=	${PREFIX}/share/doc/xine-ui
XINE_PLUGINSDIR=	lib/xine/plugins/2.2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWIN32_CODECS}
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	lirc_client:${PORTSDIR}/comms/lirc
CONFIGURE_ENV+=		LIRC_CFLAGS="-I${LOCALBASE}/include" \
			LIRC_LIBS="-L${LOCALBASE}/libs -llirc_client"
CONFIGURE_ARGS+=	--enable-lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if ${PORT_OPTIONS:MCACA}
.if !exists(${LOCALBASE}/${XINE_PLUGINSDIR}/xineplug_vo_out_caca.so)
IGNORE=		libxine should be compiled with caca support
.endif
LIB_DEPENDS+=	caca:${PORTSDIR}/graphics/libcaca
PLIST_SUB+=	CACA=""
.else
CONFIGURE_ARGS+=	--without-caca
PLIST_SUB+=	CACA="@comment "
.endif

.if ${PORT_OPTIONS:MAALIB}
LIB_DEPENDS+=	aa:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=	--with-aalib
PLIST_SUB+=	AALIB=""
.else
CONFIGURE_ARGS+=	--without-aalib --disable-aalibtest
PLIST_SUB+=	AALIB="@comment "
.endif

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc \
		&& ${INSTALL_DATA} README* ${DOCSDIR}
	@${MKDIR} ${PREFIX}/share/doc/xitk
	cd ${WRKSRC}/src/xitk/xine-toolkit \
		&& ${INSTALL_DATA} README ${PREFIX}/share/doc/xitk
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
