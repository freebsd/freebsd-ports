PORTNAME=	lxqt-policykit
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	PolicyKit authentication agent
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt6-agent-1.so:sysutils/polkit-qt-1@qt6 \
		libpolkit-agent-1.so:sysutils/polkit

USES=		cmake compiler:c++20-lang gnome gettext-runtime lxqt:2 \
		qt:6 perl5 localbase:ldflags pkgconfig tar:xz xorg

USE_PERL5=	build
USE_QT=		base:run tools:build
USE_LXQT=	buildtools2 lxqt
USE_GNOME=	glib20
USE_XORG=	x11

.include <bsd.port.mk>
