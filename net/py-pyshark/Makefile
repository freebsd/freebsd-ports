# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyshark
PORTVERSION=	0.3.6.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Pyhon packet parsing using wireshark dissectors

USES=		python zip
USE_PYTHON=	autoplist distutils

RUN_DEPENDS=	tshark>0:net/tshark \
		${PYTHON_PKGNAMEPREFIX}trollius>0:devel/py-trollius \
		${PYTHON_PKGNAMEPREFIX}logbook>0:devel/py-logbook \
		${PYTHON_PKGNAMEPREFIX}py>0:devel/py-py \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml

.include <bsd.port.mk>
