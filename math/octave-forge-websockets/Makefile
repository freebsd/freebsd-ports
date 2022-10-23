PORTNAME=	octave-forge-websockets
PORTVERSION=	0.1.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/gnu-octave/octave-websockets/archive/
DISTNAME=	v${DISTVERSIONFULL}
DIST_SUBDIR=	octave-forge/${PORTNAME}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		http://octave.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		octave-${OCTAVE_PKGNAME}-${PORTVERSION}

RUN_DEPENDS+=	${TARBALLS_DIR}/sockets.tar.gz:math/octave-forge-sockets

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

do-build:
	@${DO_NADA}

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
