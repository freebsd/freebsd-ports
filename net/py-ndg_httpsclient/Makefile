# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	ndg_httpsclient
PORTVERSION=	0.3.2
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/${DISTNAME:C/(.).*/\1/}/${PORTNAME:S/_/-/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Enhance HTTPS support for httplib and urllib2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0.13:${PORTSDIR}/security/py-openssl \
	${PYTHON_PKGNAMEPREFIX}asn1>=0.1.4:${PORTSDIR}/devel/py-asn1

USES=	python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
