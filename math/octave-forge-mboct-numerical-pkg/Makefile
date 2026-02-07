PORTNAME=	octave-forge-mboct-numerical-pkg
DISTVERSION=	0.1.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		octave autoreconf

LIB_DEPENDS+=	libgtest.so:devel/googletest \
		libmetis.so:math/metis \
		libmumps_common_seq.so:math/mumps

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/mboct-octave-pkg.tar.gz:math/octave-forge-mboct-octave-pkg

USE_GITHUB=	yes
GH_ACCOUNT=	octave-user
GH_PROJECT=	mboct-numerical-pkg

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
