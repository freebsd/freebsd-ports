PORTNAME=	octave-forge-timer
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITLAB=	yes
GL_ACCOUNT=	farhi
GL_PROJECT=	octave-timer

NO_ARCH=	yes
NO_BUILD=	yes

OCTAVE_SRC=		${GL_PROJECT}-${GL_TAGNAME}

.include <bsd.port.mk>
