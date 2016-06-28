# Created by: gahr
# $FreeBSD$

PORTNAME=	caldavzap
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://www.inf-it.com/
DISTNAME=	CalDavZAP_${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	CalDAV web client implementation

LICENSE=	AGPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		php zip
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
