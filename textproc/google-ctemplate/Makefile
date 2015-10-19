# Created by: ijliao
# $FreeBSD$

PORTNAME=	ctemplate
PORTVERSION=	2.3
CATEGORIES=	textproc
PKGNAMEPREFIX=	google-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Simple but powerful template language for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USES=		libtool pathfix pkgconfig python shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
SHEBANG_FILES=	src/template-converter src/htmlparser/generate_fsm.py src/htmlparser/fsm_config.py
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OlafvdSpek
GH_TAGNAME=	359a9f0
INSTALL_target=	install-strip

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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libctemplate.so.3.0.0
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libctemplate_nothreads.so.3.0.0

regression-test: build
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} check -C ${WRKSRC}

.include <bsd.port.mk>
