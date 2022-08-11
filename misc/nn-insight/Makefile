PORTNAME=	nn-insight
DISTVERSION=	1.0.7
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Neural network visualization software

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	avir>0:graphics/avir \
		${LOCALBASE}/include/exprtk.hpp:math/exprtk \
		flatc:devel/flatbuffers \
		half>0:math/half \
		nlohmann-json>0:devel/nlohmann-json \
		png++>0:graphics/png++
LIB_DEPENDS=	libcgraph.so:graphics/graphviz \
		libpng.so:graphics/png \
		libQCustomPlot-qt5.so:graphics/qcustomplot-qt5 \
		libtcmalloc.so:devel/google-perftools

USES=		compiler:c++17-lang cmake pkgconfig qt:5
USE_QT=		core gui svg widgets buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	yurivict

CMAKE_ARGS_aarch64=	-DENABLE_NATIVE_OPTIMIZATIONS=OFF

PLIST_FILES=	bin/nn-insight \
		libexec/nn-insight/tf-lite-plugin.so

PORTSCOUT=	limit:^.*[1-9]\. # prevent hashes

.include <bsd.port.mk>
