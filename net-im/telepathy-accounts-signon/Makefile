# $FreeBSD$

PORTNAME=	telepathy-accounts-signon
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Telepathy libaccounts and libsignon plugin

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libmission-control-plugins.so:net-im/telepathy-mission-control \
		libsignon-glib.so:net-im/libsignon-glib

USES=		gettext pkgconfig qmake qt:5 tar:bz2
USE_QT=		buildtools_build core qmake_build

USE_LDCONFIG=	YES

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	f01a6d9eccad24a3cb4a5300fb0ae0fd426cc815

PLIST_FILES=	lib/mission-control-plugins.0/mcp-account-manager-accounts-sso.so

.include <bsd.port.mk>
