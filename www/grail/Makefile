# Ports collection Makefile for:	Grail
# Version required:			0.4
# Date created:				6/11/1998
# Whom:					n@nectar.com
#
# $Id$
#

DISTNAME=		grail_04
PKGNAME=		grail-0.4
CATEGORIES=		www
MASTER_SITES=		http://monty.cnri.reston.va.us/grail-0.4/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		n@nectar.com

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python
LIB_DEPENDS=		tk80\\.1:${PORTSDIR}/x11/tk80

WRKSRC=			${WRKDIR}/${PKGNAME}

NO_CONFIGURE=		YES

CHOWN?=chown
CHMOD?=chmod
FIND?=find
PYTHON?=python
GREP?=grep

do-build:
	${PYTHON} -c 'from compileall import compile_dir; compile_dir("${WRKSRC}")'

post-extract:
	(cd ${WRKSRC} && find . -name '.cvsignore' -delete)

do-install:
	${MKDIR} ${PREFIX}/lib/grail && \
	${CHOWN} ${BINOWN}.${BINGRP} ${PREFIX}/lib/grail && \
	${CHMOD} 0555 ${PREFIX}/lib/grail
	(cd ${WRKSRC} && tar cf - .) | (cd ${PREFIX}/lib/grail && tar xf -)
	(${ECHO} "#!/bin/sh"; \
	${ECHO} 'exec python ${PREFIX}/lib/grail/grail.py $${1+"$$@"}') \
	>/tmp/grail.$$$$ && \
	${INSTALL_SCRIPT} \
	/tmp/grail.$$$$ ${PREFIX}/bin/grail

post-install:
	${CHOWN} -R ${BINOWN}.${BINGRP} ${PREFIX}/lib/grail
	${FIND} ${PREFIX}/lib/grail -type f -exec ${CHMOD} 0444 {} \;
	${FIND} ${PREFIX}/lib/grail -type d -exec ${CHMOD} 0555 {} \;

.include <bsd.port.mk>
