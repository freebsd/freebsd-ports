# Created by: sutra
# $FreeBSD$

PORTNAME=	TracSpamFilter
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	www devel python
MASTER_SITES=	http://zhoushuqun.com/files/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	trac-

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Allow different ways to reject contributions that contain spam

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}dev

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
