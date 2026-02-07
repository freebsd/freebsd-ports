PORTNAME=	RyzenAdj
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	sysutils

MAINTAINER=	vladislav.movchan@gmail.com
COMMENT=	Power management tool for Ryzen mobile and embedded CPUs
WWW=		https://github.com/FlyGoat/RyzenAdj

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to Ryzen CPUs

LIB_DEPENDS=	libpci.so:devel/libpci

USES=		cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	FlyGoat

PLIST_FILES=	bin/ryzenadj

.include <bsd.port.mk>
