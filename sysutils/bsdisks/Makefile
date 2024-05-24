PORTNAME=	bsdisks
DISTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD
WWW=		https://foss.heptapod.net/bsdutils/bsdisks

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake compiler:c++11-lang qt:6

USE_QT=		base
CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

USE_GITLAB=		yes
GL_SITE=		https://foss.heptapod.net
GL_ACCOUNT=		bsdutils
GL_TAGNAME=		205d242c512099074c3c1bf939a4fd83139bb5c8

.include <bsd.port.mk>
