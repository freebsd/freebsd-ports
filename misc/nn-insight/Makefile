# $FreeBSD$

PORTNAME=	nn-insight
DISTVERSION=	1.0.5
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Neural network visualization software

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	avir>0:graphics/avir \
		flatbuffers>0:devel/flatbuffers \
		half>0:math/half \
		nlohmann-json>0:devel/nlohmann-json \
		png++>0:graphics/png++
LIB_DEPENDS=	libcgraph.so:graphics/graphviz \
		libpng16.so:graphics/png \
		libtcmalloc.so:devel/google-perftools

USES=		compiler:c++17-lang cmake pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	yurivict
USE_QT=		core gui svg widgets buildtools_build qmake_build

PLIST_FILES=	bin/nn-insight \
		libexec/nn-insight/tf-lite-plugin.so

.include <bsd.port.mk>
