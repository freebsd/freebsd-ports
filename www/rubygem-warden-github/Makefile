# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	warden-github
PORTVERSION=	0.14.0
#PORTREVISION=	0
CATEGORIES=	www ruby
MASTER_SITES=	RG

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	A warden strategy for easy oauth integration with github

RUN_DEPENDS=	rubygem-octokit>=0:${PORTSDIR}/www/rubygem-octokit \
				rubygem-warden>=0:${PORTSDIR}/devel/rubygem-warden

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
