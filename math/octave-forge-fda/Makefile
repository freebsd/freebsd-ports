PORTNAME=	octave-forge-fda
DISTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITLAB=	yes
GL_ACCOUNT=	kakila
GL_PROJECT=	fda
GL_TAGNAME=	99f733cfa284fc0fdf911e7da97269197c4dec94

NO_ARCH=	yes
NO_BUILD=	yes

OCTAVE_SRC=		${GL_PROJECT}-${GL_TAGNAME}

.include <bsd.port.mk>
