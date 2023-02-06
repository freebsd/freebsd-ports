PORTNAME=	inputstream.adaptive
DISTVERSION=	20.3.2
DISTVERSIONSUFFIX=	-Nexus
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Adaptive stream support for Kodi
WWW=		https://github.com/peak3d/inputstream.adaptive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN=		required headers missing in multimedia/Bento4

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cmake compiler:c++14-lang kodi
USE_GITHUB=	yes
GH_ACCOUNT=	peak3d

.include <bsd.port.mk>
