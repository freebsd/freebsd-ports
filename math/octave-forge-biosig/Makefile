PORTNAME=	octave-forge-biosig
DISTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://pub.ist.ac.at/~schloegl/biosig/prereleases/
DISTNAME=	biosig4octave-${DISTVERSION}.src

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

LIB_DEPENDS+=	libbiosig.so:biology/biosig

ALL_TARGET=	# nada

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.

OCTSRC=		${DISTNAME:R}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
