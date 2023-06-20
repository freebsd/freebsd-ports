PORTNAME=	lxqt-openssh-askpass
PORTVERSION=	1.3.0
CATEGORIES=	security
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt GUI dialog for OpenSSH authentication
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

USES=	cmake compiler:c++11-lang gettext-runtime kde:5 lxqt \
	perl5 pkgconfig qt:5 tar:xz gnome xorg
USE_PERL5=	build
USE_QT=	buildtools:build qmake:build core dbus gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20
USE_XORG=	x11
.include <bsd.port.mk>
