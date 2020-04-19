# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	stagit
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://codemadness.org/releases/stagit/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Static Git page generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USE_CSTD=	c99
MAKE_ARGS=	COMPATOBJ="" \
		LIBGIT_INC="-I${LOCALBASE}/include" \
		LIBGIT_LIB="-L${LOCALBASE}/lib -lgit2"

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stagit ${WRKSRC}/stagit-index \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stagit.1 ${WRKSRC}/stagit-index.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} example_create.sh example_post-receive.sh \
		favicon.png logo.png style.css ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
