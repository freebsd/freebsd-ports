# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	tstools
DISTVERSION=	1_11
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}.berlios
MASTER_SITE_SUBDIR=	tstools
EXTRACT_SUFX=	.tgz

MAINTAINER=	fbsd@opal.com
COMMENT=	MPEG transport, program, and elementary stream tools

LICENSE=	MPL

USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${CP} ${WRKSRC}/bin/* ${PREFIX}/bin
	${CP} ${WRKSRC}/lib/* ${PREFIX}/lib
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
