PORTNAME=	octave-forge-pythonic
DISTVERSION=	0.1.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		octave python

USE_GITLAB=	yes
GL_ACCOUNT=	gnu-octave
GL_PROJECT=	octave-pythonic
GL_TAGNAME=	v0.1.2

OCTAVE_SRC=		${GL_PROJECT}-${GL_TAGNAME}

MAKE_ENV+=	PYTHON=${PYTHON_CMD} SED=gsed

.include <bsd.port.mk>
