# $FreeBSD$

PORTNAME=	ucl
PORTVERSION=	0.8.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	UCL parser and emmitter

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/libucl-${PORTVERSION}/COPYING

LIB_DEPENDS=	libucl.so:textproc/libucl

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	vstakhov
GH_PROJECT=	libucl

WRKSRC_SUBDIR=	python

.include <bsd.port.mk>
