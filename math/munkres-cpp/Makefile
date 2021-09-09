PORTNAME=	munkres-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-6
DISTVERSIONSUFFIX=	-g61086fc
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Kuhn-Munkres (Hungarian) algorithm in C++

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	saebyn

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	MUNKRESCPP_DEVEL_MODE

CMAKE_TESTING_TARGET=	tests # tests are broken, see https://github.com/saebyn/munkres-cpp/issues/31

PLIST_FILES=	include/munkres/adapters/adapter.h \
		include/munkres/matrix.cpp \
		include/munkres/matrix.h \
		include/munkres/munkres.h \
		lib/libmunkres.so

.include <bsd.port.mk>
