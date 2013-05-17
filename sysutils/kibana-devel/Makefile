# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	kibana-devel
PORTVERSION=	20130516
#PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Browser based interface to Logstash and ElasticSearch version 3

USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
GH_TAGNAME=	41ef049
GH_PROJECT=	kibana
GH_COMMIT=	41ef049

NO_BUILD=	yes

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
