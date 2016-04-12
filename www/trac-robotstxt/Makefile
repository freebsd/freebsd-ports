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

BROKEN=		unfetchable

RUN_DEPENDS=	tracd:www/trac

USES=		python:2
USE_PYTHON=	distutils autoplist

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
