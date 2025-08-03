PORTNAME=	gmm++
DISTVERSION=	5.4.4
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/getfem/stable/
DISTNAME=	${PORTNAME:S/+//g}-${DISTVERSION}

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Generic matrix template library
WWW=		https://getfem.org/gmm/

# Note: even though the port's COPYING file mentions gmm++ is licensed under
# the LGPL version 2.1 with the GCC runtime exception,
# <http://getfem.org/whatsnew/4.2.html> mentions
# v4.2 is licensed under the LGPL version 3 with the GCC runtime exception, and
# so say the headers which are installed.
LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFAULT=	SUPERLU
OPTIONS_SINGLE=		SOLVER
OPTIONS_SINGLE_SOLVER=	MUMPS SUPERLU

SOLVER_DESC=	Simultaneous equations solver
MUMPS_DESC=	Use MUMPS (math/mumps)
SUPERLU_DESC=	Use SuperLU (math/superlu)

MUMPS_RUN_DEPENDS=	${LOCALBASE}/include/cmumps_c.h:math/mumps
MUMPS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-mumps

SUPERLU_RUN_DEPENDS=	${LOCALBASE}/include/superlu/supermatrix.h:math/superlu
SUPERLU_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-superlu

.include <bsd.port.mk>
