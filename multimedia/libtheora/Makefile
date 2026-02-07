PORTNAME=	libtheora
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Theora video codec for the Ogg multimedia streaming system
WWW=		https://www.theora.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS_armv7=	as:devel/binutils
BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}

LIB_DEPENDS=	libogg.so:audio/libogg

USES_armv7=	perl5 shebangfix
USES=		autoreconf gmake libtool localbase pathfix ${USES_${ARCH}}
USE_GITLAB=	yes
GL_SITE=	https://gitlab.xiph.org
GL_ACCOUNT=	xiph
GL_PROJECT=	theora

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-sdltest \
		--disable-examples
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes
USE_PERL5=	build
SHEBANG_FILES=	lib/arm/arm2gnu.pl

# clang's own assembler doesn't like the armv7 assembly used here
CFLAGS_armv7=	-fno-integrated-as
CLFAGS+=	${CFLAGS_${ARCH}}

.include <bsd.port.mk>
