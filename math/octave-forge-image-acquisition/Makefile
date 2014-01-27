# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	octave-forge-image-acquisition
PORTVERSION=	0.1.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv3

LIB_DEPENDS=	v4l2:${PORTSDIR}/multimedia/libv4l \
		fltk:${PORTSDIR}/x11-toolkits/fltk

BROKEN=		Recent versions of libv4l do not include necessary headers

GNU_CONFIGURE=	yes

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		octave-${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	${RM} -f ${WRKSRC}/../inst/DESCRIPTION
	${RM} -f ${WRKSRC}/../inst/ltfat/DESCRIPTION
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
