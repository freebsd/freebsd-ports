# Created by: Eygene Ryabinkin <rea@FreeBSD.org>
# $FreeBSD$

PORTNAME=	defaultcc
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/trac-${PORTNAME}/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin that adds default CC value for tickets

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USES=		zip

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/trunk
REL=		10605

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
