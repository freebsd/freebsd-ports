# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	4.5
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Runs arbitrary commands when files change

# This software has code under BSD2CLAUSE license.
# All the code used in FreeBSD is under ISCL license.
LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKEFILE=	Makefile.bsd
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
TEST_TARGET=	test
PLIST_FILES=	bin/entr man/man1/entr.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/entr

.include <bsd.port.mk>
