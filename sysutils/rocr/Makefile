PORTNAME=	rocr
PORTVERSION=	1.9.1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HPC market enhanced HSA based runtime
WWW=		https://github.com/RadeonOpenCompute/ROCT-Thunk-Interface

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/src/LICENSE.md

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libhsakmt.so:sysutils/roct

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	iotamudelta
GH_PROJECT=	ROCR-Runtime
GH_TAGNAME=	5ab09ee

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
