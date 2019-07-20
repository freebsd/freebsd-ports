# $FreeBSD$

PORTNAME=	ncnn
DISTVERSION=	20190611-40
DISTVERSIONSUFFIX=	-gd3be711
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance neural network inference framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Tencent

post-install: # https://github.com/Tencent/ncnn/issues/1130
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/${PORTNAME}
	@${MV} ${STAGEDIR}${DATADIR}/* ${STAGEDIR}${PREFIX}/lib/cmake/${PORTNAME}
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
