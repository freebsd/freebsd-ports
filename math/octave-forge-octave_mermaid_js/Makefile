PORTNAME=	octave-forge-octave_mermaid_js
DISTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		octave python:3.0+
USE_GITHUB=	yes
GH_ACCOUNT=	CNOCTAVE
GH_PROJECT=	octave_mermaid_js

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
