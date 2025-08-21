PORTNAME=	rnp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://github.com/rnpgp/${PORTNAME}/releases/download/${DISTVERSIONFULL}/

MAINTAINER=	se@FreeBSD.org
COMMENT=	RNP is a set of OpenPGP (RFC4880) tools
WWW=		https://www.rnpgp.com/

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE OCB_Patent
LICENSE_COMB=	multi
LICENSE_NAME_OCB_Patent=	OCB Patent License for Ribose Inc.
LICENSE_FILE_OCB_Patent=	${WRKSRC}/LICENSE-OCB.md
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_OCB_Patent=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

LIB_DEPENDS=	libbotan-3.so:security/botan3 \
		libjson-c.so:devel/json-c
TEST_DEPENDS=	googletest>0:devel/googletest \
		gpgme>0:security/gpgme

USES=		cmake:testing compiler:c++20-lang pathfix pkgconfig \
		python:env,test shebangfix
PATHFIX_WRKSRC=	${WRKSRC}/src/lib
SHEBANG_FILES=	src/tests/cli_perf.py \
		src/tests/cli_tests.py \
		src/tests/data/cli_EncryptSign/regenerate_keys
USE_LDCONFIG=	yes

PLIST_SUB=	VERS=${DISTVERSION}

CMAKE_ON=	BUILD_SHARED_LIBS \
		CMAKE_DISABLE_FIND_PACKAGE_Git
CMAKE_OFF=	BUILD_TESTING \
		DOWNLOAD_GTEST

OPTIONS_DEFINE=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_CMAKE_BOOL=	ENABLE_DOC

pre-configure:
	${CP} ${FILESDIR}/version.cmake ${WRKSRC}/cmake/
	${REINPLACE_CMD} 's/%%DISTVERSION%%/${DISTVERSION}/' \
	    ${WRKSRC}/cmake/version.cmake

.include <bsd.port.mk>
