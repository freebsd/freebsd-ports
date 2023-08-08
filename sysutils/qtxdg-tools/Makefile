PORTNAME=	qtxdg-tools
PORTVERSION=	3.11.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	User tools for libqtxdg
WWW=		https://github.com/lxqt/qtxdg-tools

LICENSE=	LGPL21+

USES=		cmake compiler:c++14-lang gnome lxqt pkgconfig qt:5 tar:xz lxqt
USE_GNOME=	glib20
USE_QT=		buildtools:build qmake:build core dbus gui svg widgets xml
USE_LXQT=	buildtools qtxdg

.include <bsd.port.mk>
