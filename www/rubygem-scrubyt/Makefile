# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	scrubyt
PORTVERSION=	0.4.11
CATEGORIES=	www rubygems
MASTER_SITES=	RF

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Powerful web scraping toolkit written in Ruby

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-hpricot>=0.5:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-mechanize>=0.6.3:${PORTSDIR}/www/rubygem-mechanize

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

post-patch:
	${REINPLACE_CMD} 's/0.4.1/${PORTVERSION}/' ${BUILD_WRKSRC}/${GEMFILES}spec

.include <bsd.port.mk>
