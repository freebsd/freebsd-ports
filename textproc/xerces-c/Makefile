# New ports collection makefile for: xerces-c
# Date created:        29 December 2001
# Whom:                kiesel
#
# $FreeBSD$
#

PORTNAME=      xerces_c
PORTVERSION=   1.6.0
CATEGORIES=    textproc
MASTER_SITES=  http://xml.apache.org/dist/xerces-c/stable/ \
	http://document-root.de/xerces-c-mirror/
DISTNAME=      xerces-c-src1_6_0

MAINTAINER=    kiesel@schlund.de

INSTALLS_SHLIB=yes
LDCONFIG_DIRS= ${PREFIX}/lib

CONFIGURE_WRKSRC= ${WRKSRC}/src
BUILD_WRKSRC=     ${WRKSRC}/src
INSTALL_WRKSRC=   ${WRKSRC}/src

# Set this to where the source lives
MAKE_ENV+= XERCESCROOT=${WRKSRC}

# If configure fails, try this:
#CONFIGURE_SCRIPT= runConfigure -pfreebsd

USE_GMAKE=     yes
HAS_CONFIGURE= yes
GNU_CONFIGURE= yes

pre-configure:
	${CHMOD} 700 ${CONFIGURE_WRKSRC}/runConfigure
	${CHMOD} 700 ${CONFIGURE_WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/lib/libxerces-c1_6_0.so

.include <bsd.port.mk>
