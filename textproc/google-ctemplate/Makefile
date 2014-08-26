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

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig shebangfix
SHEBANG_FILES=	src/template-converter
USE_LDCONFIG=	yes

BROKEN_powerpc=	Does not compile on powerpc

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/share/doc/$$(PACKAGE)-$$(VERSION)|${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
