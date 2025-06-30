PORTNAME=	lime
DISTVERSION=	5.4.24
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	End-to-end encryption library for instant messaging
WWW=		https://www.linphone.org/technical-corner/lime

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit \
		${LOCALBASE}/lib/libbelle-sip.a:net/belle-sip \
		${LOCALBASE}/lib/libbelr.a:textproc/belr
LIB_DEPENDS=	libsoci_sqlite3.so:databases/soci

USES=	cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public

CMAKE_ARGS=	-DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

.include <bsd.port.mk>
