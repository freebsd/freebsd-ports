# Ports collection Makefile for:	Grail
# Version required:			0.4
# Date created:				6/11/1998
# Whom:					n@nectar.com
#
# $Id: Makefile,v 1.3 1998/07/04 22:07:19 nectar Exp $
#

DISTNAME=		grail-0.4
CATEGORIES=		www
MASTER_SITES=		http://monty.cnri.reston.va.us/grail-0.4/source/
DISTFILES=		grail_04.tgz

MAINTAINER=		nectar@freebsd.org

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python
LIB_DEPENDS=		tk80\\.1:${PORTSDIR}/x11-toolkits/tk80

CHOWN?=chown
CHMOD?=chmod
FIND?=find
PYTHON?=python
GREP?=grep
SED?=sed

do-build:
	${PYTHON} -c 'from compileall import compile_dir; compile_dir("${WRKSRC}")'

do-install:
	${MKDIR} ${PREFIX}/lib/grail
	(cd ${WRKSRC} && tar --exclude '.cvsignore'   \
		--exclude '*.orig' -cf - .) |         \
		(cd ${PREFIX}/lib/grail && tar xf -)
	(sed 's|%%PREFIX%%|${PREFIX}|g' <${FILESDIR}/grail                    \
		>${WRKDIR}/grail.$$$$ &&                                      \
		${INSTALL_SCRIPT} ${WRKDIR}/grail.$$$$ ${PREFIX}/bin/grail && \
		${RM} ${WRKDIR}/grail.$$$$)
	${CHOWN} -R ${BINOWN}.${BINGRP} ${PREFIX}/lib/grail
	${FIND} ${PREFIX}/lib/grail -type f -exec ${CHMOD} 0444 {} \;
	${FIND} ${PREFIX}/lib/grail -type d -exec ${CHMOD} 0555 {} \;

.include <bsd.port.mk>
