PORTNAME=	accounts-qml-module
DISTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	sysutils kde
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Expose the Online Accounts API to QML applications
WWW=		https://gitlab.com/groups/accounts-sso

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-qt5.so:net-im/libaccounts-qt@qt5 \
		libsignon-qt5.so:sysutils/signond@qt5

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5 tar:bz2
USE_GL=		gl
USE_QT=		core declarative gui network testlib xml \
		buildtools:build qdoc:build qmake:build
# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	cfadea7ba8ba4011ae20d771696eb74deb87201e

.include <bsd.port.mk>
