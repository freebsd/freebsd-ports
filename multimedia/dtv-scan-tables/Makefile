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
GH_PROJECT=	dtv-scan-tables
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	14bd6c7

NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
		@${MKDIR} ${STAGEDIR}${DATADIR}
		@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.post.mk>
