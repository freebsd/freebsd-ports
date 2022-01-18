PORTNAME=	chemicalfun
DISTVERSION=	g20220104
CATEGORIES=	science # chemistry
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${PORTNAME}/get/${BB_COMMIT}${EXTRACT_SUFX}?dummy=/:src
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for working with chemical reactions and formulas

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json

USES=		cmake:testing eigen:3

BB_ACCOUNT=	gems4
BB_COMMIT=	dd673f906517

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${PORTNAME}-${BB_COMMIT}

CMAKE_OFF=	CHEMICALFUN_BUILD_PYTHON
CMAKE_TESTING_ON=	CHEMICALFUN_BUILD_TESTS # tests fail to compile, BitBucket offers no easy way to report this

.include <bsd.port.mk>
