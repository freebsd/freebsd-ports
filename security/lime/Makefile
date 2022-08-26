PORTNAME=	lime
PORTVERSION=	5.0.8
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	End-to-end encryption library for instant messaging

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
	libbellesip.so:net/belle-sip \
	libsoci_sqlite3.so:databases/soci

USES=	cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	242c5b26a62ccd8d9ecaa7efbd15aa7697fe027b

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO

.include <bsd.port.mk>
