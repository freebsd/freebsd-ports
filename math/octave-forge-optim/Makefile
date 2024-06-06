PORTNAME=	octave-forge-optim
PORTVERSION=	1.6.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	Parts
LICENSE_NAME=	See individual files for licenses
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/statistics.tar.gz:math/octave-forge-statistics \
		${OCTAVE_TARBALLS_DIR}/struct.tar.gz:math/octave-forge-struct

USES=		octave shebangfix

SHEBANG_FILES=	*.pl

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
