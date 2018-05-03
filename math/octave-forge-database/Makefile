# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	octave-forge-database
PORTVERSION=	2.4.2
PORTREVISION=	5
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

RUN_DEPENDS+=	${TARBALLS_DIR}/struct.tar.gz:math/octave-forge-struct

BROKEN=		does not build with octave version 4.4.0

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

GNU_CONFIGURE=	yes
USES+=		pgsql

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

post-patch:
	${REINPLACE_CMD} 's#postgresql/##' ${WRKSRC}/*
	${REINPLACE_CMD} 's#endian.h#sys/endian.h#' ${WRKSRC}/wrap_endian.h

.include <bsd.port.mk>
