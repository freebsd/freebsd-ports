PORTNAME=	octave-forge-pythonic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
PORTREVISION=	3
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

OCTAVE_SRC=		${GL_PROJECT}-${GL_TAGNAME}

MAKE_ENV+=	PYTHON=${PYTHON_CMD} SED=gsed

.include <bsd.port.mk>
