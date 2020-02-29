# $FreeBSD$

PORTNAME=	vmaf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ea25229433f7.patch:-p2

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Perceptual video quality assessment based on multi-method fusion

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_FILE=	${WRKSRC:H}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		compiler:c++11-lib meson
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	Netflix
WRKSRC_SUBDIR=	lib${PORTNAME}
CFLAGS_i386=	-msse # https://github.com/Netflix/vmaf/issues/374

.include <bsd.port.mk>
