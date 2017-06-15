# Created by: Sergey Kozlov <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	bokeh
PORTVERSION=	0.12.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kozlov.sergey.404@gmail.com
COMMENT=	Interactive Web Plotting for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}requests>=1.2.3:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.3:www/py-tornado

USES=		python
USE_PYTHON=	autoplist distutils concurrent

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} == 2700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>3.0.3:devel/py-futures
.endif

.include <bsd.port.post.mk>
