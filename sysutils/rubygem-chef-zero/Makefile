# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	chef-zero
PORTVERSION=	1.6.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Self-contained Chef server for testing and solo setup purposes

RUN_DEPENDS=	rubygem-puma>=1.6:${PORTSDIR}/www/rubygem-puma \
		rubygem-mixlib-log>=1.3:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-hashie>=2.0:${PORTSDIR}/devel/rubygem-hashie \
		rubygem-moneta<0.7.0:${PORTSDIR}/devel/rubygem-moneta \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/chef-zero

.include <bsd.port.mk>
