PORTNAME=	octave-forge-ltfat
PORTVERSION=	2.6.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	https://github.com/ltfat/ltfat/releases/download/v2.6.0/
DISTNAME=	${OCTAVE_PKGNAME}-${PORTVERSION}-of

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libportaudio.so:audio/portaudio \
		libopenblas.so:math/openblas

USES=		octave

OCTAVE_SRC=		${OCTAVE_PKGNAME}

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	${RM} ${WRKSRC}/../inst/DESCRIPTION
	${RM} ${WRKSRC}/../inst/ltfat/DESCRIPTION
	${RM} ${WRKSRC}/../inst/ltfat/inst/DESCRIPTION
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTAVE_SRC}

.include <bsd.port.mk>
