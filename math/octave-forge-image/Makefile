# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-image
PORTVERSION=	2.4.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

USES=		compiler:c++0x
GNU_CONFIGURE=	yes

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
BROKEN=		Doesn't build on FreeBSD 9 or older
.endif

.include <bsd.port.post.mk>
