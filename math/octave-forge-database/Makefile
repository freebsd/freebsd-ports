# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	octave-forge-database
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

GNU_CONFIGURE=	yes
USE_PGSQL=	yes
ALL_TARGET=

NO_STAGE=	yes
.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

post-patch:
	${REINPLACE_CMD} 's#postgresql/##' ${WRKSRC}/*
	${REINPLACE_CMD} 's#endian.h#sys/endian.h#' ${WRKSRC}/wrap_endian.h

.include <bsd.port.mk>
