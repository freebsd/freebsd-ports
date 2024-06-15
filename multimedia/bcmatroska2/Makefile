PORTNAME=	bcmatroska2
PORTVERSION=	5.2.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications Matroska media container support
WWW=		https://www.linphone.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STATIC=NO

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.post.mk>
