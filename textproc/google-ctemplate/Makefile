# Created by: ijliao
# $FreeBSD$

PORTNAME=	ctemplate
PORTVERSION=	2.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	textproc
PKGNAMEPREFIX=	google-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Simple but powerful template language for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USES=		libtool pathfix pkgconfig python:build shebangfix
GNU_CONFIGURE=	yes
SHEBANG_FILES=	src/template-converter src/htmlparser/generate_fsm.py src/htmlparser/fsm_config.py
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OlafvdSpek
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/share/doc/$$(PACKAGE)-$$(VERSION)|${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
# XXX: undefining BSWAP32 breaks builds on big-endian systems for some reason
	@${REINPLACE_CMD} -e 's|# undef BSWAP32|//&|' \
		${WRKSRC}/src/base/macros.h

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
