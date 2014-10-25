# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urljr
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.openidenabled.com/resources/downloads/python-openid/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Common interface to HTTP fetchers for PycURL or urllib2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/curl:${PORTSDIR}/ftp/py-curl

BROKEN=		fails checksum
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
