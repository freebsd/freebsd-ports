PORTNAME=	chaco
DISTVERSION=	2.2
CATEGORIES=	math
MASTER_SITES=	https://ftp.mcs.anl.gov/pub/petsc/externalpackages/
DISTNAME=	Chaco-${DISTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Software for partitioning graphs
WWW=		https://github.com/sandialabs/Chaco/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../GNU_Lesser_GPL.txt

USES=		gmake
MAKE_ARGS=	CFLAGS="${CFLAGS}"
WRKSRC=		${WRKDIR}/${DISTNAME}/code

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/exec/chaco ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/libchaco.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/*.ps ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*.ps

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/*.graph ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/*.coords ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
