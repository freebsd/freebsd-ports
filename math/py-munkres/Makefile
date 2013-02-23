# Created by:	Mark Felder <feld@feld.me>
# $FreeBSD$

PORTNAME=	munkres
PORTVERSION=	1.0.5.4
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@feld.me
COMMENT=	A Python implementation of the munkres algorithm

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bmc
GH_TAGNAME=	release-${PORTVERSION}
GH_COMMIT=	fbd9fd9

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/munkres.py \
		%%PYTHON_SITELIBDIR%%/munkres.pyc \
		%%PYTHON_SITELIBDIR%%/munkres.pyo

.include <bsd.port.mk>
