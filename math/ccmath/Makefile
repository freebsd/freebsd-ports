# New ports collection makefile for:   ccmath
# Date created:        07 March 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       ccmath
PORTVERSION=	2.2.0
CATEGORIES=     math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	greid@ukug.uk.freebsd.org

INSTALLS_SHLIB=	yes

post-configure:
.if (${MACHINE_ARCH} != "i386")
	(cd ${WRKSRC} && ${SH} non_intel.sh)
.endif

do-build:
	(cd ${WRKSRC} && ${SH} makelibs.sh)

do-install:
	${INSTALL_DATA} ${WRKSRC}/ccmath.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tmp/libccm.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/tmp/libccm.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ccmath
	${INSTALL_DATA} ${WRKSRC}/manual/* ${PREFIX}/share/doc/ccmath
.endif

.include <bsd.port.mk>
