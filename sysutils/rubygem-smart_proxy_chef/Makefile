# Created by: Michael Moll <ruby@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smart_proxy_chef
PORTVERSION=	0.1.8
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Chef Plug-In for Foreman\'s Smart Proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	foreman-proxy>=1.8.0:net/foreman-proxy \
		rubygem-chef-api>0:sysutils/rubygem-chef-api

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/settings.d/chef.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/chef.yml.sample
	${INSTALL_DATA} ${WRKSRC}/bundler.d/chef.rb \
		${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/chef.rb

.include <bsd.port.mk>
