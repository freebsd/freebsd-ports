# $FreeBSD$

PORTNAME=	signon-plugin-oauth2
DISTVERSION=	0.24
PORTREVISION=	3
CATEGORIES=	sysutils kde
DISTNAME=	archive
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Signon OAuth 1.0 and 2.0 plugin for accounts-sso

LIB_DEPENDS=	libsignon-qt5.so:sysutils/signon-qt5

USES=		compiler:c++11-lang pkgconfig python qmake qt:5
USE_QT=		core network testlib \
		buildtools_build qmake_build
USE_LDCONFIG=	${PREFIX}/lib/signon

QMAKE_ENV=	PREFIX=${PREFIX}

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	2dd9ba521a0dd4277c4bf6970a7f4e3894fd85ae

# Fix for  Qt5-5.13:
# oauth2plugin.cpp:133:9: error: 'addQueryItem' is deprecated [-Werror,-Wdeprecated-declarations]
#  url.addQueryItem(CLIENT_ID, d->m_oauth2Data.ClientId());
#      ^
post-patch:
	${REINPLACE_CMD} '/-Werror/d' ${PATCH_WRKSRC}/common-project-config.pri

.include <bsd.port.mk>
