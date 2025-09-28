PORTNAME=	libcpuid
DISTVERSION=	0.8.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/anrieff/libcpuid/releases/download/v${DISTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small x86 CPU identification library
WWW=		https://libcpuid.sourceforge.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix python:test shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	tests/run_tests.py
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

PORTDOCS=	AUTHORS ChangeLog Readme.md

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=		doxygen:devel/doxygen
MANPAGES_CONFIGURE_ENV_OFF=	ac_cv_prog_DOXYGEN=

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
