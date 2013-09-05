# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	kibana-devel
PORTVERSION=	20130905
#PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Browser based interface to Logstash and ElasticSearch version 3

USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
GH_TAGNAME=	9798f8b
GH_PROJECT=	kibana
GH_COMMIT=	9798f8b

NO_BUILD=	yes

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
