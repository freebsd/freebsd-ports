PORTNAME=	sdcv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Text-based utility for work with dictionaries in StarDict's format #'
WWW=		https://dushistov.github.io/sdcv/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	jq>0:textproc/jq

USES=		cmake:testing compiler:c++11-lang gnome pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	Dushistov
USE_GNOME=	glib20

CMAKE_TESTING_ON=	BUILD_TESTS

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=OFF

post-patch:
.for i in doc/sdcv.1 doc/uk/sdcv.1 src/sdcv.cpp tests/t_list
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' ${WRKSRC}/${i}
.endfor

post-build-NLS-on:
	cd ${BUILD_WRKSRC} && ${MAKE_CMD} lang

.include <bsd.port.mk>
