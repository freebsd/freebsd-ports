PORTNAME=	bsdisks
DISTVERSION=	0.34
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD
WWW=		https://foss.heptapod.net/bsdutils/bsdisks

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt

USES=		cmake compiler:c++11-lang qt:5

USE_QT=		qmake:build buildtools:build core dbus

USE_GITLAB=		yes
GL_SITE=		https://foss.heptapod.net
GL_ACCOUNT=		bsdutils
GL_TAGNAME=		03a25a7cad28b5342c347360f66d12ef7a20a359

.include <bsd.port.mk>
