PORTNAME=	octave-forge-ponchon-savarit
PORTVERSION=	0.1.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/aumpierre-unb/Ponchon-Savarit-for-GNU-Octave/archive/refs/tags/
DISTNAME=	v${PORVERSION}0.1.0

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		http://octave.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		Ponchon-Savarit-for-GNU-Octave-${PORTVERSION}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

do-build:
	@${DO_NADA}

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
