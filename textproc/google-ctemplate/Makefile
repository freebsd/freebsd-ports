PORTNAME=	ctemplate
PORTVERSION=	2.4
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	textproc
PKGNAMEPREFIX=	google-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Simple but powerful template language for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USES=		autoreconf gmake libtool pathfix pkgconfig python:build shebangfix
GNU_CONFIGURE=	yes
SHEBANG_FILES=	src/template-converter src/htmlparser/generate_fsm.py src/htmlparser/fsm_config.py
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OlafvdSpek
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-patch:
# XXX: undefining BSWAP32 breaks builds on big-endian systems for some reason
	@${REINPLACE_CMD} -e 's|# undef BSWAP32|//&|' \
		${WRKSRC}/src/base/macros.h

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e \
		's|dist_doc_DATA|noinst_DOCDATA|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
