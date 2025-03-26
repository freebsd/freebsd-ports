PORTNAME=	bcmatroska2
DISTVERSION=	5.4.2
CATEGORIES=	multimedia

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications Matroska media container support
WWW=		https://www.linphone.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit

USES=		cmake compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}

#.include <bsd.port.pre.mk>

#.if ${COMPILER_TYPE} == clang
#CFLAGS+=	-Wno-error=incompatible-function-pointer-types
#.endif

.include <bsd.port.mk>
