# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dashing
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tj@FreeBSD.org
COMMENT=	HTML dashboard framwork based on sinatra

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sass32>=3.2.12:${PORTSDIR}/textproc/rubygem-sass32 \
		rubygem-coffee-script>=2.3.0:${PORTSDIR}/devel/rubygem-coffee-script \
		rubygem-execjs>=2.2.2:${PORTSDIR}/devel/rubygem-execjs \
		rubygem-sinatra>=1.4.5:${PORTSDIR}/www/rubygem-sinatra \
		rubygem-sinatra-contrib>=1.4.2:${PORTSDIR}/www/rubygem-sinatra-contrib \
		rubygem-thin>=1.6.2:${PORTSDIR}/www/rubygem-thin \
		rubygem-rufus-scheduler>=3.0.9:${PORTSDIR}/devel/rubygem-rufus-scheduler \
		rubygem-thor>=0.19.1:${PORTSDIR}/devel/rubygem-thor \
		rubygem-sprockets>=2.12.2:${PORTSDIR}/devel/rubygem-sprockets \
		rubygem-rack15>=1.5.0:${PORTSDIR}/www/rubygem-rack15 \
		rubygem-rake>=10.3.2:${PORTSDIR}/devel/rubygem-rake \
		rubygem-bundler>=1.7.3:${PORTSDIR}/sysutils/rubygem-bundler

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/dashing

.include <bsd.port.mk>
