# Created by: Stephen Montgomery-Smith <stephen@FreeBSd.org>
# $FreeBSD$

PORTNAME=	octave-forge-database
PORTVERSION=	2.0.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

#USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_PGSQL=	yes
ALL_TARGET=

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

post-patch:
	${REINPLACE_CMD} 's#postgresql/##' ${WRKSRC}/*
	${REINPLACE_CMD} 's#endian.h#sys/endian.h#' ${WRKSRC}/*

.include <bsd.port.post.mk>
