# $FreeBSD$

PORTNAME=	kensa
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Heroku Add-On provider tool

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST= yes

PLIST_FILES=	bin/kensa

RUN_DEPENDS+=	rubygem-launchy22>=0:${PORTSDIR}/devel/rubygem-launchy22 \
		rubygem-mechanize26>=0:${PORTSDIR}/www/rubygem-mechanize26 \
		rubygem-rest-client>=0:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-term-ansicolor>=0:${PORTSDIR}/devel/rubygem-term-ansicolor \
		rubygem-sinatra>=1.4.2:${PORTSDIR}/www/rubygem-sinatra \
		rubygem-foreman>=0.63:${PORTSDIR}/devel/rubygem-foreman \
		rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-thin>=0:${PORTSDIR}/www/rubygem-thin \
		rubygem-tilt1>=1.4.1:${PORTSDIR}/devel/rubygem-tilt1 \
		rubygem-haml>=4.0.5:${PORTSDIR}/www/rubygem-haml \
		rubygem-heroku-nav>=0.2.2:${PORTSDIR}/www/rubygem-heroku-nav \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json


.include <bsd.port.mk>
