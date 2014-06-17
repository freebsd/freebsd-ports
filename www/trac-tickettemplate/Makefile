# Created by: Eygene Ryabinkin <rea@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tickettemplate
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/trac-${PORTNAME}/
PKGNAMEPREFIX=	trac-
DISTNAME=	trac${PORTNAME}plugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for making ticket templates

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USES=		zip
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

WRKSRC=		${WRKDIR}/trac${PORTNAME}plugin/0.11
REL=		10605

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
