# $FreeBSD$

PORTNAME=	gpg-gui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	security

MAINTAINER=	nc@FreeBSD.org
COMMENT=	GUI wrapper for symmetric GPG file encryption

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
RUN_DEPENDS=	gpg2:security/gnupg

USES=		gnome meson pkgconfig
USE_GNOME=	glib20 gtk30
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AnsgarKlein
GH_PROJECT=	GPG-Gui

.include <bsd.port.mk>
