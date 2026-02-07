PORTNAME=	octave-forge-symbolic
PORTVERSION=	3.2.2
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BUILD_DEPENDS+=	isympy:math/py-sympy@${PY_FLAVOR}
RUN_DEPENDS+=	isympy:math/py-sympy@${PY_FLAVOR}

USES=		octave python

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
