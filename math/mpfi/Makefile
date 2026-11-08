PORTNAME=	mpfi
PORTVERSION=	1.5.5
CATEGORIES=	math
#MASTER_SITES=	https://perso.ens-lyon.fr/nathalie.revol/softwares/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Multiple Precision Floating-point Interval library
WWW=		https://perso.ens-lyon.fr/nathalie.revol/software.html

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	makeinfo:print/texinfo
LIB_DEPENDS=	libgmp.so:math/gmp		\
		libmpfr.so:math/mpfr

USES=		autoreconf libtool localbase tar:bz2

USE_GITLAB=	yes
GL_SITE=	https://gitlab.inria.fr

INFO=		${PORTNAME}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

.include <bsd.port.mk>
