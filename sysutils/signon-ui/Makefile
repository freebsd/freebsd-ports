# $FreeBSD$

PORTNAME=	signon-ui
PORTVERSION=	0.17
PORTREVISION=	2
CATEGORIES=	sysutils kde
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component for handling accounts-sso user interactions

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-qt5.so:net-im/libaccounts-qt5 \
		libnotify.so:devel/libnotify \
		libsignon-qt5.so:sysutils/signon-qt5 \
		libproxy.so:net/libproxy

USES=		compiler:c++11-lang pkgconfig python qmake qt:5 tar:bz2
USE_QT=		buildtools_build qmake_build webkit widgets

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	075830f31096947fcea70802b8d3c142bccfbefa

.include <bsd.port.mk>
