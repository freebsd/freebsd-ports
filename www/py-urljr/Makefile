# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urljr
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.openidenabled.com/resources/downloads/python-openid/
MASTER_SITES=	http://openidenabled.com/files/python-openid/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Common interface to HTTP fetchers for PycURL or urllib2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/curl:${PORTSDIR}/ftp/py-curl

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
