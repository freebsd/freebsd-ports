# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-signal
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

RUN_DEPENDS+=	${TARBALLS_DIR}/specfun.tar.gz:${PORTSDIR}/math/octave-forge-specfun
RUN_DEPENDS+=	${TARBALLS_DIR}/control.tar.gz:${PORTSDIR}/math/octave-forge-control
RUN_DEPENDS+=	${TARBALLS_DIR}/general.tar.gz:${PORTSDIR}/math/octave-forge-general

NO_STAGE=	yes
.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-patch:
	${REINPLACE_CMD} s/-Wall// ${WRKSRC}/Makefile

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
