PORTNAME=	octave-forge-octave_mermaid_js
DISTVERSION=	2.0.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		octave python:3.0+
USE_GITHUB=	yes
GH_ACCOUNT=	CNOCTAVE
GH_PROJECT=	octave_mermaid_js

DEPRECATED=	this version seems to require RUN_DEPENDS currently unavailable on FreeBSD

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
