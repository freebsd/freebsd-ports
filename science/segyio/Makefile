PORTNAME=	segyio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.6
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to interact with SEG-Y & Seismic Unix formatted seismic data

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/License.md

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	equinor

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_PYTHON

.include <bsd.port.mk>
