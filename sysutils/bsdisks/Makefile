PORTNAME=	bsdisks
DISTVERSION=	0.38
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD
WWW=		https://foss.heptapod.net/bsdutils/bsdisks

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake compiler:c++11-lang qt:6

USE_QT=		base
CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

USE_GITLAB=	yes
GL_SITE=	https://foss.heptapod.net
GL_ACCOUNT=	bsdutils

.include <bsd.port.mk>
