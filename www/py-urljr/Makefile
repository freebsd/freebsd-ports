# New ports collection makefile for:	urljr
# Date created:				2006-12-19
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	urljr
PORTVERSION=	1.0.0
CATEGORIES=	www python
MASTER_SITES=	http://www.openidenabled.com/resources/downloads/python-openid/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Common interface to HTTP fetchers for PycURL or urllib2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/curl:${PORTSDIR}/ftp/py-curl

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
