# Created by: Dreamcat4 <dreamcat4@gmail.com>
# $FreeBSD$

PORTNAME=	dtv-scan-tables
PORTVERSION=	20140612
CATEGORIES=	multimedia

MAINTAINER=	dreamcat4@gmail.com
COMMENT=	Digital TV scan tables from linuxtv.org

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	oliv3r
GH_TAGNAME=	14bd6c7

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${DATADIR}
		@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
