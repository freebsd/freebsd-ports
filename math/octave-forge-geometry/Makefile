PORTNAME=	octave-forge-geometry
PORTVERSION=	4.0.0
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USES=		python:env

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml
RUN_DEPENDS+=	${TARBALLS_DIR}/matgeom.tar.gz:math/octave-forge-matgeom

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
