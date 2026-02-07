PORTNAME=	qhttpengine
DISTVERSION=	1.0.1-5
PORTREVISION=	3
DISTVERSIONSUFFIX=	-g43f55df
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HTTP server for Qt applications
WWW=		https://github.com/nitroshare/qhttpengine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	nitroshare
USE_QT=		core network buildtools:build qmake:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
