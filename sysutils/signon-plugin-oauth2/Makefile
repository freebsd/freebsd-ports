PORTNAME=	signon-plugin-oauth2
DISTVERSION=	0.25
PORTREVISION=	3
CATEGORIES=	sysutils kde
DISTNAME=	archive
DIST_SUBDIR=	KDE/${GL_ACCOUNT}
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Signon OAuth 1.0 and 2.0 plugin for accounts-sso
WWW=		https://gitlab.com/accounts-sso/signon-plugin-oauth2

LIB_DEPENDS=	libsignon-qt6.so:sysutils/signond

USES=		compiler:c++11-lang pkgconfig python qmake qt:6
USE_QT=		base
USE_LDCONFIG=	${PREFIX}/lib/signon

QMAKE_ENV=	PREFIX=${PREFIX}

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	nicolasfella
GL_TAGNAME=	fab698862466994a8fdc9aa335c87b4f05430ce6

.include <bsd.port.mk>
