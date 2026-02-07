PORTNAME=	gpg-gui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI wrapper for symmetric GPG file encryption
WWW=		https://github.com/AnsgarKlein/GPG-Gui

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gpg2:security/gnupg

USES=		gnome meson pkgconfig vala:build
USE_GNOME=	glib20 gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	AnsgarKlein
GH_PROJECT=	GPG-Gui

.include <bsd.port.mk>
