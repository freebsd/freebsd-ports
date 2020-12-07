# $FreeBSD$

PORTNAME=	vmaf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Perceptual video quality assessment based on multi-method fusion

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_FILE=	${WRKSRC:H}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		compiler:c++11-lib meson
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	Netflix
WRKSRC_SUBDIR=	lib${PORTNAME}

.include <bsd.port.mk>
