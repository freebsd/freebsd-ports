# Created by: Torsten Zühlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	dddbl
PORTVERSION=	2.0.1
CATEGORIES=	www
MASTER_SITES=	http://www.dddbl.de/dddbl-versions/

MAINTAINER=	ports@toco-domains.de
COMMENT=	Definition Driven Database Layer for PHP

USES=		tar:bzip2

.include <bsd.port.options.mk>

NO_BUILD=	yes

USE_PHP=	yes

WRKSRC=		${WRKDIR}/dddbl2

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
