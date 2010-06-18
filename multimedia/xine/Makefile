# New ports collection makefile for:    xine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.99.6
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-ui/${PORTVERSION}
DISTNAME=	${PORTNAME}-ui-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	An X11 multimedia player

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine \
		png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_XZ=		yes
USE_XORG=	x11 xt xv xinerama xxf86vm
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
MAKE_JOBS_SAFE=	yes

MANLANG=	"" de es fr pl
MAN1_EN=	aaxine.1 xine-bugreport.1 xine-check.1 xine-remote.1 xine.1
MAN1_DE=	${MAN1_EN}
MAN1_ES=	${MAN1_EN}
MAN1_FR=	xine.1
MAN1_PL=	aaxine.1 xine-remote.1 xine.1

OPTIONS=	CACA "Enable libcaca output" off \
		AALIB "Enable aalib output" off \
		LIRC "Enable lirc support" off \
		CURL "Enable curl support" on \
		WIN32_CODECS "Enable win32 codecs (for i386 only)" on \
		NLS "Enable Native Language Support" on \
		XFT "Enable Xft support" on

DOCSDIR=	${PREFIX}/share/doc/xine-ui

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
.if !defined(WITHOUT_WIN32_CODECS)
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.endif
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if !defined(WITHOUT_XFT)
USE_XORG+=	xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=	--enable-lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if defined(WITH_CACA)
LIBXINE_VER=	1.26
.if !exists(${LOCALBASE}/lib/xine/plugins/${LIBXINE_VER}/xineplug_vo_out_caca.so)
IGNORE=libxine should be compiled with caca support
.endif
LIB_DEPENDS+=	caca.0:${PORTSDIR}/graphics/libcaca
PLIST_SUB+=	WITH_CACA=""
.else
PLIST_SUB+=	WITH_CACA="@comment "
CONFIGURE_ARGS+=	--without-caca --disable-cacatest
.endif

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	WITH_AALIB=""
CONFIGURE_ARGS+=	--with-aalib
.else
PLIST_SUB+=	WITH_AALIB="@comment "
CONFIGURE_ARGS+=	--without-aalib --disable-aalibtest
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g' \
		${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
