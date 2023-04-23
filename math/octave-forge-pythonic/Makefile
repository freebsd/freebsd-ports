PORTNAME=	octave-forge-pythonic
DISTVERSION=	0.0.1+
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		octave python

USE_GITLAB=	yes
GL_ACCOUNT=	mtmiller
GL_PROJECT=	octave-pythonic
GL_COMMIT=	3dbe9a06c1dec1a138f398b951e18044a00e063d

OCTAVE_SRC=		${GL_PROJECT}-${GL_COMMIT}

MAKE_ENV+=	PYTHON=${PYTHON_CMD} SED=gsed

.include <bsd.port.mk>
