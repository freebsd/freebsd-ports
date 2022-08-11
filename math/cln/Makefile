PORTNAME=	cln
PORTVERSION=	1.3.6
CATEGORIES=	math devel
MASTER_SITES=	http://www.ginac.de/CLN/ \
		http://www.mirrors.wiretapped.net/security/cryptography/libraries/math/cln/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Class Library for Numbers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USES=		compiler:c11 gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes

INFO=		cln

CPPFLAGS+=	${CPPFLAGS_${ARCH}}
CPPFLAGS_aarch64=	-DNO_ASM
CPPFLAGS_armv6=	-DNO_ASM
CPPFLAGS_armv7=	-DNO_ASM

.include <bsd.port.mk>
