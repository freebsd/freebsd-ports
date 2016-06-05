# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	robotxt
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	www devel python
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracRobotsTxt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows simple management of a robots.txt

RUN_DEPENDS=	tracd:www/trac

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
