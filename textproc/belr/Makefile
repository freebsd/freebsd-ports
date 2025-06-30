PORTNAME=	belr
DISTVERSION=	5.4.24
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Language recognition library
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit

USES=		cmake compiler:c++17-lang dos2unix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	${WRKSRC}/CMakeLists.txt

CMAKE_ARGS=	-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DENABLE_STRICT=NO

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
