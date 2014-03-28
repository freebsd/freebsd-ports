# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	2.8
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/ \
		https://bitbucket.org/eradman/entr/get/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Runs arbitrary commands when files change

# This software has code under BSD2CLAUSE license.
# All the code used in FreeBSD is under ISCL license.
LICENSE=	ISCL

WRKSRC=		${WRKDIR}/eradman-entr-9192ece7198c

MAKEFILE=	Makefile.bsd
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
PLIST_FILES=	bin/entr man/man1/entr.1.gz

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} ${MAKE_ARGS} test)

.include <bsd.port.mk>
