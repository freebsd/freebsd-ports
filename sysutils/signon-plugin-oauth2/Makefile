PORTNAME=	signon-plugin-oauth2
DISTVERSION=	0.25
PORTREVISION=	2
CATEGORIES=	sysutils kde
DISTNAME=	archive
DIST_SUBDIR=	KDE/${GL_ACCOUNT}
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Signon OAuth 1.0 and 2.0 plugin for accounts-sso
WWW=		https://gitlab.com/accounts-sso/signon-plugin-oauth2

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

LIB_DEPENDS=	libsignon-qt${FLAVOR:S/qt//}.so:sysutils/signond@${FLAVOR}

USES=		compiler:c++11-lang pkgconfig python qmake qt:${FLAVOR:S/qt//}
_USE_QT_qt5=	core network testlib \
		buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}
USE_LDCONFIG=	${PREFIX}/lib/signon

QMAKE_ENV=	PREFIX=${PREFIX}

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	nicolasfella
GL_TAGNAME=	fab698862466994a8fdc9aa335c87b4f05430ce6

# Fix for  Qt5-5.13:
# oauth2plugin.cpp:133:9: error: 'addQueryItem' is deprecated [-Werror,-Wdeprecated-declarations]
#  url.addQueryItem(CLIENT_ID, d->m_oauth2Data.ClientId());
#      ^
post-patch:
	${REINPLACE_CMD} '/-Werror/d' ${PATCH_WRKSRC}/common-project-config.pri

.include <bsd.port.mk>
