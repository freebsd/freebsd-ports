# Ports collection Makefile for:	Grail
# Date created:				1/11/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		grail
PORTVERSION= 		0.6
CATEGORIES=		www python
MASTER_SITES=		http://grail.cnri.reston.va.us/grail/source/
DISTNAME=		${PORTNAME}-06
EXTRACT_SUFX=		.tgz

MAINTAINER=		nectar@freebsd.org

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		${PREFIX}/lib/python1.5/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=			${WRKDIR}/${PKGNAME}

GRAILSUBDIR=		share/grail
GRAILDIR=		${PREFIX}/${GRAILSUBDIR}
DIRS_CMD=		${SED} -e '/^@dirrm/bok' -e 'D' -e ':ok' -e 's,@dirrm ,,' < ${PLIST}
FILES_CMD=		${SED} -e '/^share\//bok' -e 'D' -e ':ok' -e 's,${GRAILSUBDIR}/,,' < ${PLIST}

FIND?=find
PYTHON?=python

do-build:
	${PYTHON} -u -c 'from compileall import compile_dir; compile_dir("${WRKSRC}")'

do-install:
	@${ECHO} === Creating directories...
	@for dir in `${DIRS_CMD}`; do                                  \
		${ECHO} ${PREFIX}/$$dir;                               \
		${MKDIR} ${PREFIX}/$$dir;                              \
	done
	@${ECHO} === Installing grail files ...
	@for file in `${FILES_CMD}`; do                                \
		${ECHO} ${GRAILDIR}/$$file;                            \
		${INSTALL_DATA} ${WRKSRC}/$$file ${GRAILDIR}/$$file;   \
	done
	@${ECHO} === Installing grail script...
	@${SED} 's,%%GRAILDIR%%,${GRAILDIR},g' <${FILESDIR}/grail >    \
		${WRKDIR}/grail.tmp
	@${INSTALL_SCRIPT} ${WRKDIR}/grail.tmp ${PREFIX}/bin/grail
	@${RM} ${WRKDIR}/grail.tmp

.include <bsd.port.mk>
