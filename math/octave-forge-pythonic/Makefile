PORTNAME=	octave-forge-pythonic
DISTVERSION=	0.0.1+
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		python
MAKE_ENV+=	PYTHON=${PYTHON_CMD} SED=gsed

USE_GITLAB=	yes
GL_ACCOUNT=	mtmiller
GL_PROJECT=	octave-pythonic
GL_COMMIT=	3dbe9a06c1dec1a138f398b951e18044a00e063d

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${GL_PROJECT}-${GL_COMMIT}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
