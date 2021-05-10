PORTNAME=	antic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.4
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Algebraic Number Theory In C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

LIB_DEPENDS=	libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wbhart

PLIST_FILES=	include/antic/nf.h \
		include/antic/nf_elem.h \
		include/antic/qfb.h \
		lib/libantic.so \
		lib/libantic.so.0 \
		lib/libantic.so.0.2.4

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libantic.so

.include <bsd.port.mk>
