PORTNAME=	mpfi
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://perso.ens-lyon.fr/nathalie.revol/softwares/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Multiple Precision Floating-point Interval library
WWW=		https://perso.ens-lyon.fr/nathalie.revol/software.html

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	makeinfo:print/texinfo
LIB_DEPENDS=	libgmp.so:math/gmp		\
		libmpfr.so:math/mpfr

USES=		libtool localbase tar:bz2

INFO=		${PORTNAME}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
