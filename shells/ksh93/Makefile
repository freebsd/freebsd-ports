# New ports collection makefile for:	ksh93
# Version required:	98
# Date created:		1999-10-24
# Whom:			Christian Weisgerber <naddy@mips.rhein-neckar.de>
#
# $FreeBSD$
#

# ast-base-99 is linked dynamically for BSD/OS and will not work
DISTNAME=		ast-base-98.bsd.i386
PKGNAME=		ksh-19931228
CATEGORIES=     	shells
# Users must register with AT&T before downloading tarball.
#MASTER_SITES=		http://www.research.att.com/sw/tools/reuse/
EXTRACT_SUFX=		.tgz

MAINTAINER=		naddy@mips.rhein-neckar.de

ONLY_FOR_ARCHS=		i386
RESTRICTED=		"Requires user to register with AT&T."

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
MAN1=		ksh93.1
STRIP=

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	  ${ECHO} ""; \
	  ${ECHO} "Please read http://www.research.att.com/sw/tools/reuse/"; \
	  ${ECHO} "for details of how to obtain the ksh93 binary.  Put the"; \
	  ${ECHO} "file ${DISTFILES} in the directory"; \
	  ${ECHO} "${DISTDIR} and run make again."; \
	  ${ECHO} ""; \
	  exit 1; \
	fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ksh ${PREFIX}/bin/ksh93
	${INSTALL_MAN} ${WRKSRC}/man/man1/sh.1 ${PREFIX}/man/man1/ksh93.1

.include <bsd.port.mk>
