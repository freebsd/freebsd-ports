# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	Coherence
PORTVERSION=	0.6.6.2
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	DLNA/UPnP media server and framework for the digital living

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.3:devel/py-configobj@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>8.2:devel/py-twisted@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Louie>0:devel/py-louie@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	coherence-project
GH_TAGNAME=	4d5ee5f

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
