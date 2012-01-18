# New ports collection makefile for:	octave-forge-signal
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-signal
PORTVERSION=	1.1.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

RUN_DEPENDS+=	${TARBALLS_DIR}/optim.tar.gz:${PORTSDIR}/math/octave-forge-optim
RUN_DEPENDS+=	${TARBALLS_DIR}/specfun.tar.gz:${PORTSDIR}/math/octave-forge-specfun
RUN_DEPENDS+=	${TARBALLS_DIR}/control.tar.gz:${PORTSDIR}/math/octave-forge-control

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
post-patch:
	${REINPLACE_CMD} s/-Wall// ${WRKSRC}/Makefile

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.post.mk>
