PORTNAME=	libcpuid
PORTVERSION=	0.6.5
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/anrieff/libcpuid/releases/download/v${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small x86 CPU identification library
WWW=		https://libcpuid.sourceforge.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix python:test shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

SHEBANG_FILES=	tests/run_tests.py

PORTDOCS=	AUTHORS ChangeLog Readme.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
