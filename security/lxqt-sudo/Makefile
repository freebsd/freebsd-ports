# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-sudo
PORTVERSION=	0.14.1
CATEGORIES=	security
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	GUI frontend to su/sudo for LXQt desktop

LICENSE=	LGPL21+

RUN_DEPENDS=	sudo:security/sudo

USES=	cmake compiler:c++14-lang gettext kde:5 lxqt qt:5 \
	pkgconfig tar:xz
USE_QT=	buildtools_build qmake_build core dbus gui svg widgets \
	x11extras xml

USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt

.include <bsd.port.mk>
