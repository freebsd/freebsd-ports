# New ports collection makefile for:    xine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.99.4
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-ui-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	An X11 multimedia player

LIB_DEPENDS=	xine.15:${PORTSDIR}/multimedia/libxine \
		aa.1:${PORTSDIR}/graphics/aalib \
		png.5:${PORTSDIR}/graphics/png

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name=""

MANLANG=	"" de es fr pl
MAN1=		aaxine.1 xine-bugreport.1 xine-check.1 xine-remote.1 xine.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
.if !defined(WITHOUT_WIN32_CODECS)
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.endif
.endif

.if ${OSVERSION} == 500043
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src:xitk:common.h
.endif

# PRIi64 macro is not defined
.if ${OSVERSION} < 500040
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src:xitk:common.h-1
.endif

# mbrtowc() is not implemented
.if ${OSVERSION} < 500039
CONFIGURE_ARGS+=	--disable-mbs
# Xft support requires --enable-mbs configure option
WITHOUT_XFT=	yes
.endif

.if ${OSVERSION} < 502000
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
CONFIGURE_ARGS+=	--with-readline=${LOCALBASE}
.endif

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if !defined(WITHOUT_LIBCACA) && (exists(${LOCALBASE}/lib/libcaca.a) || defined(WITH_LIBCACA))
PLIST_SUB+=	WITH_LIBCACA=""
.else
PLIST_SUB+=	WITH_LIBCACA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g' ${WRKSRC}/configure
.if ${OSVERSION} >= 500035
	@${REINPLACE_CMD} -e \
		 's|-malign-loops|-falign-loops|g ; \
		  s|-malign-jumps|-falign-jumps|g ; \
		  s|-malign-functions|-falign-functions|g' ${WRKSRC}/configure
.endif
	@${RM} ${WRKSRC}/src/xitk/xine-remote.c

post-install:
.for l in es fr
	@${CP} ${PREFIX}/man/man1/aaxine.1 ${PREFIX}/man/${l}/man1/aaxine.1
.endfor
.for l in es fr pl
	@${CP} ${PREFIX}/man/man1/xine-bugreport.1 ${PREFIX}/man/${l}/man1/xine-bugreport.1
.endfor
.for l in es fr pl
	@${CP} ${PREFIX}/man/man1/xine-check.1 ${PREFIX}/man/${l}/man1/xine-check.1
.endfor
.for l in es fr
	@${CP} ${PREFIX}/man/man1/xine-remote.1 ${PREFIX}/man/${l}/man1/xine-remote.1
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
