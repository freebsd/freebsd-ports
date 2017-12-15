# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	tstools
DISTVERSION=	1_11
CATEGORIES=	multimedia
MASTER_SITES=	BERLIOS

MAINTAINER=	fbsd@opal.com
COMMENT=	MPEG transport, program, and elementary stream tools

LICENSE=	MPL11

MAKE_JOBS_UNSAFE=	yes

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
