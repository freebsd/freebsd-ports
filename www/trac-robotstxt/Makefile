# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	robotxt
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	www devel python
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracRobotsTxt-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Allows simple management of a robots.txt

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
