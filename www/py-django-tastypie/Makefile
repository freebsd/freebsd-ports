# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	django-tastypie
PORTVERSION=	0.10.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Create REST API for Django apps

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mimeparse>=0:${PORTSDIR}/devel/py-mimeparse \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:${PORTSDIR}/devel/py-dateutil
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}django>=1.5:${PORTSDIR}/www/py-django

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYTHON_PY3K_PLIST_HACK=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[[:<:]]setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
