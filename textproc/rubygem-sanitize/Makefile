# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	sanitize
PORTVERSION=	2.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Whitelist based HTML sanitizer

RUN_DEPENDS=	rubygem-crass>=0.2.0:${PORTSDIR}/www/rubygem-crass \
		rubygem-nokogiri>=1.4.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-nokogumbo>=1.1.12:${PORTSDIR}/textproc/rubygem-nokogumbo

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
