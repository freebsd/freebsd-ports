PORTNAME=	uvg266
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VVC encoder based on Kvazaar
WWW=		https://ultravideo.fi/#encoder_x

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		vvdecapp:multimedia/vvdec

USES=		cmake:testing compiler:c11 python:test
USE_GITHUB=	yes
GH_ACCOUNT=	ultravideo
GH_TUPLE=	silentbicycle:greatest:v1.0.0:greatest/greatest
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	BUILD_TESTS
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/DecoderAppStatic/vvdecapp/' \
		-e 's,\.\./bin,${BUILD_WRKSRC},' \
		${WRKSRC}/tests/util.sh
	@${REINPLACE_CMD} -e 's/python3/${PYTHON_CMD:T}/' \
		${WRKSRC}/tests/test_cabac_state.sh

.include <bsd.port.mk>
