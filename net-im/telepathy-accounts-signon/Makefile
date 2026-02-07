PORTNAME=	telepathy-accounts-signon
DISTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Telepathy libaccounts and libsignon plugin
WWW=		https://gitlab.com/accounts-sso/telepathy-accounts-signon

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libmission-control-plugins.so:net-im/telepathy-mission-control \
		libsignon-glib.so:net-im/libsignon-glib \
		libtelepathy-glib.so:net-im/telepathy-glib

USES=		gettext gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20

USE_LDCONFIG=	YES

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	0af244284e6b04c4abe5373d43bbc88a235d84aa

PLIST_FILES=	lib/mission-control-plugins.0/mcp-account-manager-accounts-sso.so

.include <bsd.port.mk>
