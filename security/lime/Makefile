PORTNAME=	lime
DISTVERSION=	5.4.72
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	End-to-end encryption library for instant messaging
WWW=		https://gitlab.linphone.org/BC/public/lime

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libsoci_sqlite3.so:databases/soci

USES=	cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_UNIT_TESTS

.include <bsd.port.mk>
