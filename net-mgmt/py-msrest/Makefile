# Created by: Johannes Jost Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	msrest
PORTVERSION=	0.4.14
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johannes@perceivon.net
COMMENT=	AutoRest swagger generator Python client runtime

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.5.4:devel/py-isodate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>0:www/py-requests-oauthlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34@${FLAVOR}
.endif

.include <bsd.port.post.mk>
