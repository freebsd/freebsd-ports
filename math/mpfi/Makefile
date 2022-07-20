PORTNAME=	mpfi
PORTVERSION=	1.5.4
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/38111/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Multiple Precision Floating-point Interval library

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	makeinfo:print/texinfo
LIB_DEPENDS=	libgmp.so:math/gmp		\
		libmpfr.so:math/mpfr

USES=		autoreconf libtool localbase

INFO=		${PORTNAME}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
