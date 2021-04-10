PORTNAME=	inputstream.adaptive
DISTVERSION=	2.6.11
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Adaptive stream support for Kodi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cmake compiler:c++14-lang kodi
USE_GITHUB=	yes
GH_ACCOUNT=	peak3d

.include <bsd.port.mk>
