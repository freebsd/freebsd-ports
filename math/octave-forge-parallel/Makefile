# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-parallel
PORTVERSION=	4.0.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

RUN_DEPENDS+=	${TARBALLS_DIR}/struct.tar.gz:math/octave-forge-struct

WRKSRC=		${WRKDIR}/${OCTSRC}/src
GNU_CONFIGURE=	yes
USES+=		compiler:gcc-c++11-lib perl5 shebangfix
USE_PERL5=	build
SHEBANG_FILES=	*.pl

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
