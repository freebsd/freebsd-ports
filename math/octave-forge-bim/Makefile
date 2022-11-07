PORTNAME=	octave-forge-bim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.6
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	carlodefalco
GH_PROJECT=	bim

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${GH_PROJECT}-${DISTVERSION}

RUN_DEPENDS+=	${TARBALLS_DIR}/fpl.tar.gz:math/octave-forge-fpl
RUN_DEPENDS+=	${TARBALLS_DIR}/msh.tar.gz:math/octave-forge-msh

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

do-build:
	@${DO_NADA}

NO_ARCH=	yes

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
