PORTNAME=	lxqt-sudo
PORTVERSION=	1.4.0
CATEGORIES=	security
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	GUI frontend to su/sudo for LXQt desktop
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

RUN_DEPENDS=	sudo:security/sudo

USES=		cmake gettext kde:5 lxqt qt:5 perl5 tar:xz gnome xorg
USE_PERL5=	build
USE_QT=		buildtools:build core dbus gui svg qmake:build widgets \
		x11extras xml

USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20
USE_XORG=	x11

.include <bsd.port.mk>
