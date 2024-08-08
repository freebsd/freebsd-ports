PORTNAME=	sdcv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
CATEGORIES=	textproc

MAINTAINER=	citrin@citrin.ru
COMMENT=	Text-based utility for work with dictionaries in StarDict's format #'
WWW=		https://dushistov.github.io/sdcv/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	jq>0:textproc/jq

USES=		cmake compiler:c++11-lang gnome pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	Dushistov
USE_GNOME=	glib20

CMAKE_ON=	BUILD_TESTS
TEST_TARGET=	test

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=OFF

post-patch:
.for i in doc/sdcv.1 src/sdcv.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|' ${WRKSRC}/${i}
.endfor

post-build-NLS-on:
	cd ${BUILD_WRKSRC} && ${MAKE_CMD} lang

.include <bsd.port.mk>
