# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	TracDuplicates
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	GH
PKGNAMEPREFIX=	trac-

MAINTAINER=	gslin@gslin.org
COMMENT=	Notice original ticket to dupe one

BROKEN=		Fails to patch
DEPRECATED=	Broken for more than 5 months
EXPIRATION_DATE=	2014-06-30

LICENSE=	BSD

RUN_DEPENDS=	trac>=0:${PORTSDIR}/www/trac

GH_ACCOUNT=	nmaier
GH_COMMIT=	22976dd
USE_GITHUB=	yes

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
