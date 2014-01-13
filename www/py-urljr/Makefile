# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urljr
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	http://www.openidenabled.com/resources/downloads/python-openid/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Common interface to HTTP fetchers for PycURL or urllib2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/curl:${PORTSDIR}/ftp/py-curl

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-urljr

NO_STAGE=	yes
.include <bsd.port.mk>
