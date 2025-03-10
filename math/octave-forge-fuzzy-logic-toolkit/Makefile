PORTNAME=	octave-forge-fuzzy-logic-toolkit
DISTVERSION=	0.6.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	lmarkowsky
GH_PROJECT=	fuzzy-logic-toolkit

OCTAVE_SRC=	${OCTAVE_PKGNAME}-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

.include <bsd.port.mk>
