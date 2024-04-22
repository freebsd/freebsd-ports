PORTNAME=	lxqt-policykit
PORTVERSION=	1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	PolicyKit authentication agent
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt5-agent-1.so:sysutils/polkit-qt-1@qt5 \
		libpolkit-agent-1.so:sysutils/polkit

USES=		cmake compiler:c++14-lang gnome gettext-runtime kde:5 qt:5 perl5 \
		localbase:ldflags lxqt pkgconfig tar:xz xorg

USE_PERL5=	build
USE_QT=		buildtools:build qmake:build core dbus gui linguisttools \
		svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20
USE_XORG=	x11

.include <bsd.port.mk>
