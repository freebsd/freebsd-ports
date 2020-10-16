# Created by: Mike Meyer <mwm@mired.org>
# $FreeBSD$

PORTNAME=	beautifulsoup
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.crummy.com/software/BeautifulSoup/bs3/download//3.x/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	32
DISTNAME=	BeautifulSoup-${PORTVERSION}

MAINTAINER=	mwm@mired.org
COMMENT=	HTML/XML Parser for Python

LICENSE=	BSD3CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-11-15

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

CONFLICTS=	py[0-9]*-beautifulsoup-3.0.*

.include <bsd.port.mk>
