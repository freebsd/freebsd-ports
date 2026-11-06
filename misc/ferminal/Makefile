PORTNAME=ferminal
DISTVERSION=1.3.3
CATEGORIES=misc

DISTNAME=${PORTNAME}-${DISTVERSION}

MAINTAINER=rangga19sj@gmail.com
COMMENT=Custom Wrapper CLI to make your work faster
WWW=https://github.com/RangS-1/Ferminal

LICENSE=MIT

USE_GITHUB=yes
GH_ACCOUNT=RangS-1
GH_PROJECT=Ferminal
GH_TAGNAME=v${DISTVERSION}

USES=python
USE_GITHUB=yes
USE_PYTHON=autoplist pep517
RUN_DEPENDS= \
	     ${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR}

.include <bsd.port.mk>
