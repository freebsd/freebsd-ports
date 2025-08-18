PORTNAME=	hyprpolkitagent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Polkit authentication agent written in QT/QML
WWW=		https://github.com/hyprwm/hyprpolkitagent

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libpolkit-agent-1.so:sysutils/polkit \
		libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake gettext-runtime gl gnome pkgconfig qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_GL=		gl opengl
USE_GNOME=	glib20
USE_QT=		base declarative

PLIST_FILES=	lib/systemd/user/${PORTNAME}.service \
		libexec/${PORTNAME} \
		share/dbus-1/services/org.hyprland.${PORTNAME}.service

.include <bsd.port.mk>
