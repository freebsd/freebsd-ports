# New ports collection makefile for: xerces-c
# Date created:        29 December 2001
# Whom:                kiesel
#
# $FreeBSD$
#

PORTNAME=	xerces_c
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://archive.apache.org/dist/xml/%SUBDIR%/ \
		http://document-root.de/xerces-c-mirror/
MASTER_SITE_SUBDIR=	xerces-c/Xerces-C_${PORTVERSION:S/./_/g}
DISTNAME=	xerces-c-src${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xerces-C++ is a validating XML parser written in a subset of C++

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib

XERCESWRKSRC=	${WRKSRC}/src/xercesc
CONFIGURE_WRKSRC=	${XERCESWRKSRC}
BUILD_WRKSRC=		${XERCESWRKSRC}
INSTALL_WRKSRC=		${XERCESWRKSRC}

USE_GMAKE=	yes
MAKE_ENV+=	XERCESCROOT=${WRKSRC}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ENV+=	XERCESCROOT=${WRKSRC} TRANSCODER="IconvFBSD"
CONFIGURE_ARGS=	-p freebsd -n socket -P ${PREFIX}
.if defined(NO_THREADS)
CONFIGURE_ARGS+=	-r none
.endif

PLIST_SUB+=	XERCESC_VER=${PORTVERSION:S/./_/g} \

pre-configure:
	${CHMOD} 700 ${CONFIGURE_WRKSRC}/runConfigure
	${CHMOD} 700 ${CONFIGURE_WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/lib/libxerces-c${PORTVERSION:S/./_/g}.so

.include <bsd.port.mk>
