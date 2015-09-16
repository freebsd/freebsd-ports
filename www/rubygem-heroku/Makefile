# $FreeBSD$

PORTNAME=	heroku
PORTVERSION=	3.9.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Heroku Client

LICENSE=	MIT

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST= yes

PLIST_FILES=	bin/heroku

RUN_DEPENDS+=	rubygem-heroku-api>=0:${PORTSDIR}/www/rubygem-heroku-api \
		rubygem-excon>=0:${PORTSDIR}/devel/rubygem-excon \
		rubygem-multi_json>=0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-launchy>=0:${PORTSDIR}/devel/rubygem-launchy \
		rubygem-netrc>=0:${PORTSDIR}/net/rubygem-netrc \
		rubygem-rest-client>=0:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-rqrcode>=0:${PORTSDIR}/www/rubygem-rqrcode \
		rubygem-rubyzip>=0:${PORTSDIR}/archivers/rubygem-rubyzip \
		rubygem-term-ansicolor>=0:${PORTSDIR}/devel/rubygem-term-ansicolor \
		rubygem-tins>=0:${PORTSDIR}/devel/rubygem-tins

.include <bsd.port.mk>
