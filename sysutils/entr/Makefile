# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/ \
		https://bitbucket.org/eradman/entr/get/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Runs arbitrary commands when files change

# This software has code under BSD2CLAUSE license.
# All the code used in FreeBSD is under ISCL license.
LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/eradman-entr-f4e2cbe57708

MAKEFILE=	Makefile.bsd
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
TEST_TARGET=	test
PLIST_FILES=	bin/entr man/man1/entr.1.gz

.include <bsd.port.mk>
