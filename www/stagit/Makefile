# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	stagit
PORTVERSION=	0.7.2
CATEGORIES=	www
MASTER_SITES=	http://dl.2f30.org/releases/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Static Git page generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		localbase:ldflags
USE_CSTD=	c99

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS} -lgit2"

post-patch:
	@${REINPLACE_CMD} '/strlcat\.o/d; /strlcpy\.o/d' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/stagit ${WRKSRC}/stagit-index ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stagit.1 ${WRKSRC}/stagit-index.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.for f in example_create.sh example_post-receive.sh favicon.png logo.png style.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
