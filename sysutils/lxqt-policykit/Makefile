PORTNAME=	lxqt-policykit
PORTVERSION=	1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	PolicyKit authentication agent
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt5-agent-1.so:sysutils/polkit-qt \
		libpolkit-agent-1.so:sysutils/polkit

USES=	cmake compiler:c++14-lang gettext-runtime kde:5 qt:5 gnome \
	localbase:ldflags lxqt perl5 pkgconfig tar:xz xorg
USE_PERL5=	build
USE_QT=	buildtools:build qmake:build core dbus gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20
USE_XORG=	x11
.include <bsd.port.mk>
