# Ports collection Makefile for:	Grail
# Version required:			0.5
# Date created:				1/11/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.6 1999/01/10 18:52:34 nectar Exp $
#

DISTNAME=		grail_05
PKGNAME=		grail-0.5
CATEGORIES=		www
MASTER_SITES=		http://monty.cnri.reston.va.us/grail-0.5/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nectar@freebsd.org

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python
LIB_DEPENDS=		tk80.1:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=			${WRKDIR}/${PKGNAME}

GRAILDIR=		${PREFIX}/share/grail

CHOWN?=chown
CHMOD?=chmod
FIND?=find
PYTHON?=python

do-build:
	${PYTHON} -u -c 'from compileall import compile_dir; compile_dir("${WRKSRC}")'

do-install:
	${MKDIR} ${GRAILDIR}
	${TAR} --exclude '.cvsignore' -C ${WRKSRC} -cf - . |           \
		${TAR} -C ${GRAILDIR} -xvf -
	${SED} 's|%%GRAILDIR%%|${GRAILDIR}|g' <${FILESDIR}/grail >     \
		${WRKDIR}/grail.tmp
	${INSTALL_SCRIPT} ${WRKDIR}/grail.tmp ${PREFIX}/bin/grail
	${RM} ${WRKDIR}/grail.tmp
	${CHOWN} -R ${BINOWN}:${BINGRP} ${GRAILDIR}
	${FIND} ${GRAILDIR} -type f -exec ${CHMOD} 0444 {} \;
	${FIND} ${GRAILDIR} -type d -exec ${CHMOD} 0555 {} \;

.include <bsd.port.mk>
