# Created by: Torsten Zühlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	dddbl
PORTVERSION=	2.0.1
CATEGORIES=	www
MASTER_SITES=	http://www.dddbl.de/dddbl-versions/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Definition Driven Database Layer for PHP

USES=		tar:bzip2

NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	yes

WRKSRC=		${WRKDIR}/dddbl2

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
