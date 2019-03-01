# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	stagit
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	https://codemadness.org/releases/stagit/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Static Git page generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		localbase:ldflags
USE_CSTD=	c99

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		COMPATOBJ="" \
		LDFLAGS="${LDFLAGS} -lgit2"

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/stagit ${WRKSRC}/stagit-index ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stagit.1 ${WRKSRC}/stagit-index.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
.for f in example_create.sh example_post-receive.sh favicon.png logo.png style.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
