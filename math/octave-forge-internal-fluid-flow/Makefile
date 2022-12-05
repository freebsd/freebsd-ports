PORTNAME=	octave-forge-internal-fluid-flow
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	aumpierre-unb
GH_PROJECT=	internal-Fluid-Flow-for-GNU-Octave

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		Internal-Fluid-Flow-for-GNU-Octave-${DISTVERSION}

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

do-build:
	@${DO_NADA}

NO_ARCH=	yes

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
