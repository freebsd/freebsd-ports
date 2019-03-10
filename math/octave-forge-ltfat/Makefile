# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	octave-forge-ltfat
PORTVERSION=	2.3.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libportaudio.so:audio/portaudio \
		libcblas.so:math/cblas

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

GNU_CONFIGURE=	yes

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	${RM} ${WRKSRC}/../inst/DESCRIPTION
	${RM} ${WRKSRC}/../inst/ltfat/DESCRIPTION
	${RM} ${WRKSRC}/../inst/ltfat/inst/DESCRIPTION
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
