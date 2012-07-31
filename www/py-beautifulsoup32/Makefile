# New ports collection makefile for:	beautifulsoup
# Date created:				15 July 2005
# Whom:					Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	beautifulsoup
PORTVERSION=	3.2.0
CATEGORIES=	www python
MASTER_SITES=	http://www.crummy.com/software/BeautifulSoup/download/3.x/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BeautifulSoup-${PORTVERSION}

MAINTAINER=	mwm@mired.org
COMMENT=	HTML/XML Parser for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	BeautifulSoup

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}32

CONFLICTS=	py[0-9]*-beautifulsoup-3.0.*

.include <bsd.port.mk>
