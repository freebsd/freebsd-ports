# $FreeBSD$

PORTNAME=	signon-ui
PORTVERSION=	0.17
CATEGORIES=	sysutils kde
MASTER_SITES=	https://gitlab.com/${GL_ACCOUNT}/${GL_PROJECT}/repository/archive${EXTRACT_SUFX}?ref=${GL_TAGNAME}&num;/ \
		LOCAL/tcberner/${GL_ACCOUNT}/
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component for handling accounts-sso user interactions

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-qt5.so:net-im/libaccounts-qt5 \
		libnotify.so:devel/libnotify \
		libsignon-qt5.so:sysutils/signon-qt5 \
		libproxy.so:net/libproxy

USES=		pkgconfig python qmake tar:bz2
USE_QT5=	buildtools_build qmake_build webkit widgets

# gitlab variables
GL_ACCOUNT=	accounts-sso
GL_PROJECT=	signon-ui
GL_TAGNAME=	075830f31096947fcea70802b8d3c142bccfbefa
WRKSRC=		${WRKDIR}/${GL_PROJECT}-${GL_TAGNAME}-${GL_TAGNAME}

.include <bsd.port.mk>
