# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-odepkg
PORTVERSION=	0.8.5
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

BROKEN=		not a valid package for Octave version >= 4.2.1
DEPRECIATED=	not a valid package for Octave version >= 4.2.1
EXPIRATION_DATE=	2018-04-24

USES+=		dos2unix
DOS2UNIX_GLOB=	*.diff

MAKE_JOBS_UNSAFE=	yes

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
