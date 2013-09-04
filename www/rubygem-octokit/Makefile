# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	octokit
PORTVERSION=	1.23.0
#PORTREVISION=	0
CATEGORIES=	www ruby
MASTER_SITES=	RG

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Simple wrapper for the GitHub API

RUN_DEPENDS=	rubygem-sawyer>=0:${PORTSDIR}/www/rubygem-sawyer \
	rubygem-addressable>=0:${PORTSDIR}/www/rubygem-addressable \
	rubygem-faraday_middleware>=0:${PORTSDIR}/www/rubygem-faraday_middleware \
	rubygem-hashie>=0:${PORTSDIR}/devel/rubygem-hashie \
	rubygem-multi_json>=0:${PORTSDIR}/devel/rubygem-multi_json \
	rubygem-netrc>=0:${PORTSDIR}/net/rubygem-netrc

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
