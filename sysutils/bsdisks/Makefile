PORTNAME=	bsdisks
DISTVERSION=	0.33
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
GL_TAGNAME=		4750994746f4f99355b30ae7db29598ef632ac2e

.include <bsd.port.mk>
