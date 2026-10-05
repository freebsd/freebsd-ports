PORTNAME=	qhttpengine
DISTVERSION=	1.0.1-5
DISTVERSIONSUFFIX=	-g43f55df
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HTTP server for Qt applications
WWW=		https://github.com/nitroshare/qhttpengine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=		Obsolete: hasn't been updated in 8 years, the only users in general are legacy apps
EXPIRATION_DATE=	2026-12-31

USES=		cmake compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	nitroshare
USE_QT=		core network buildtools:build qmake:build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility

.include <bsd.port.mk>
