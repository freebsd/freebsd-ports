# Created by: ijliao
# $FreeBSD$

PORTNAME=	google-ctemplate
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	ctemplate
DISTNAME=	ctemplate-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Simple but powerful template language for C++

OPTIONS_DEFINE=	DOCS

USES=		libtool pathfix pkgconfig shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
SHEBANG_FILES=	src/template-converter
USE_LDCONFIG=	yes

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

regression-test: build
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} check -C ${WRKSRC}

.include <bsd.port.mk>
