# Ports collection Makefile for:	Grail
# Date created:				1/11/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	grail
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=grail
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	An extensible Internet browser written entirely in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

IGNORE=		"Doesn't seem to work with Python 2.x"

USE_PYTHON=	yes
GRAILSUBDIR=	share/grail
GRAILDIR=	${PREFIX}/${GRAILSUBDIR}
DIRS_CMD=	${SED} -e '/^@dirrm/bok' -e 'D' -e ':ok' -e 's,@dirrm ,,' < ${PLIST}
FILES_CMD=	${SED} -e '/^share\//bok' -e 'D' -e ':ok' -e 's,${GRAILSUBDIR}/,,' < ${PLIST}

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
