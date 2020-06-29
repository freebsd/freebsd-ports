# $FreeBSD$

PORTNAME=	svt-av1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.4
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scalable AV1 encoder

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_i386=	https://github.com/OpenVisualCloud/SVT-AV1/issues/1231

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake compiler:c11
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	OpenVisualCloud
GH_PROJECT=	SVT-AV1
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	NATIVE YASM

.include <bsd.port.mk>
