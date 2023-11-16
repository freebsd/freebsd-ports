PORTNAME=	octave-forge-parallel
PORTVERSION=	4.0.2
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

NOT_FOR_ARCHS=	armd64

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/struct.tar.gz:math/octave-forge-struct

USES=		compiler:gcc-c++11-lib octave perl5 shebangfix
USE_PERL5=	build

SHEBANG_FILES=	*.pl

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
