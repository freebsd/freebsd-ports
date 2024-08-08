PORTNAME=	dlpack
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0rc
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common in-memory tensor structure
WWW=		https://dmlc.github.io/dlpack/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang python:run shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc

PLIST_FILES=	include/dlpack/dlpack.h \
		lib/cmake/dlpack/dlpackConfig.cmake \
		lib/cmake/dlpack/dlpackConfigVersion.cmake \
		lib/cmake/dlpack/dlpackTargets.cmake

NO_ARCH=	yes

.include <bsd.port.mk>
