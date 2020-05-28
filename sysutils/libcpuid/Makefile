# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcpuid
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small x86 CPU identification library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64

USE_GITHUB=	yes
GH_ACCOUNT=	anrieff

USES=		autoreconf libtool pathfix python:test shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

python_OLD_CMD=	/usr/bin/env\ python2.7
SHEBANG_FILES=	tests/create_test.py tests/run_tests.py

PORTDOCS=	AUTHORS ChangeLog Readme.md

OPTIONS_DEFINE=	DOCS

pre-test:
	2to3-${PYTHON_VER} --no-diffs --write ${WRKSRC}/tests

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
