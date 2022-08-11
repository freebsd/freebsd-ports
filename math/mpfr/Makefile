PORTNAME=	mpfr
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	https://www.mpfr.org/mpfr-${PORTVERSION}/ \
		GNU
DIST_SUBDIR=	${DISTNAME}

PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Library for multiple-precision floating-point computations

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libgmp.so:math/gmp

PATCHLEVEL=	13
PATCHFILES!=	/usr/bin/jot -s " " -w patch%02d ${PATCHLEVEL} 1 ${PATCHLEVEL}

USES=		gmake libtool makeinfo tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		mpfr

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
