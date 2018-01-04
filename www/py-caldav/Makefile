# $FreeBSD$

PORTNAME=	caldav
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	CalDAV (RFC4791) client library

LICENSE=	APACHE20 GPLv3
LICENSE_COMB=	dual

USES=		python
USE_PYTHON=	distutils autoplist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.6.0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.8.1:deskutils/py-vobject@${FLAVOR}

.include <bsd.port.mk>
