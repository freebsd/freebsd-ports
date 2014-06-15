# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	feedgenerator
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Standalone version of django.utils.feedgenerator

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON=		yes

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
