PORTNAME=	bsdisks
DISTVERSION=	0.35
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD
WWW=		https://foss.heptapod.net/bsdutils/bsdisks

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt-1@qt5

USES=		cmake compiler:c++11-lang qt:5

USE_QT=		qmake:build buildtools:build core dbus

USE_GITLAB=		yes
GL_SITE=		https://foss.heptapod.net
GL_ACCOUNT=		bsdutils
GL_TAGNAME=		205d242c512099074c3c1bf939a4fd83139bb5c8

.include <bsd.port.mk>
