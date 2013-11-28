# Created by: Kozlov Sergey <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	django-tables2
PORTVERSION=	0.14.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kozlov.sergey.404@gmail.com
COMMENT=	Table/data-grid framework for Django

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}six>=0:${PORTSDIR}/devel/py-six

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_AUTOPLIST=yes

post-patch:
	@${REINPLACE_CMD} 's|classifiers=\[|zip_safe=False, classifiers=\[|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
