# $FreeBSD$

PORTNAME=	signon-plugin-oauth2
DISTVERSION=	0.24
CATEGORIES=	sysutils kde
DISTNAME=	archive

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Signon OAuth 1.0 and 2.0 plugin for accounts-sso

LIB_DEPENDS=	libsignon-qt5.so:sysutils/signon-qt5

USES=		pkgconfig python qmake
USE_QT5=	core network testlib \
		buildtools_build qmake_build
USE_LDCONFIG=	${PREFIX}/lib/signon

QMAKE_ENV=	PREFIX=${PREFIX}

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	2dd9ba521a0dd4277c4bf6970a7f4e3894fd85ae

.include <bsd.port.mk>
