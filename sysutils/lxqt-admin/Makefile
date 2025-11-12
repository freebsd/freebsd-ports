PORTNAME=	lxqt-admin
PORTVERSION=	2.3.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	System administration tool for the LXQt desktop
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake compiler:c++20-lang gnome kde:6 localbase lxqt:2 \
		perl5 pkgconfig tar:xz qt:6 xorg
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_LXQT=	buildtools2 lxqt
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_XORG=	x11

.include <bsd.port.mk>
