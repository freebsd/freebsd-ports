PORTNAME=	octave-forge-fda
PORTVERSION=	1.0.0
CATEGORIES=	math
MASTER_SITES=	https://gitlab.com/kakila/fda/-/archive/master/
DISTNAME=	fda-master

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		http://octave.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		fda-master

WRKSRC=		${WRKDIR}/${OCTSRC}/src

do-build:
	@${DO_NADA}

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
