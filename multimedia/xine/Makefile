# New ports collection makefile for:    xine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://xine.sourceforge.net/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-ui-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

LIB_DEPENDS=	xine.0:${PORTSDIR}/graphics/libxine \
		aa.1:${PORTSDIR}/graphics/aalib \
		png.5:${PORTSDIR}/graphics/png \
		intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32

MANLANG=	"" es fr pl
MAN1=		aaxine.1 xine.1

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
.if !defined(WITHOUT_WIN32_CODECS)
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CODEC_PORT=	${PORTSDIR}/graphics/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.endif
.endif

post-patch:
	@${PERL} -pi -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g' ${WRKSRC}/configure

post-install:
	@${CP} ${PREFIX}/man/man1/aaxine.1 ${PREFIX}/man/fr/man1/aaxine.1
	@${CP} ${PREFIX}/man/man1/aaxine.1 ${PREFIX}/man/es/man1/aaxine.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
