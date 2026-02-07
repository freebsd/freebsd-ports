PORTNAME=	accounts-qml-module
DISTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	sysutils kde
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Expose the Online Accounts API to QML applications
WWW=		https://gitlab.com/groups/accounts-sso

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-qt6.so:net-im/libaccounts-qt@qt6 \
		libsignon-qt6.so:sysutils/signond@qt6

USES=		compiler:c++17-lang gl pkgconfig qmake qt:6 tar:bz2
USE_GL=		gl
USE_QT=		base declarative \
		tools:build
# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	05e79ebbbf3784a87f72b7be571070125c10dfe3

.include <bsd.port.mk>
