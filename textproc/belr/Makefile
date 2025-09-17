PORTNAME=	belr
DISTVERSION=	5.4.28
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Language recognition library
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbcunit.so:devel/bcunit

USES=		cmake compiler:c++17-lang dos2unix
DOS2UNIX_FILES=	${WRKSRC}/CMakeLists.txt
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
