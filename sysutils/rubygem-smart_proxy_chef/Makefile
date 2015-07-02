# Created by: Michael Moll <mmoll@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smart_proxy_chef
PORTVERSION=	0.1.4
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	Chef Plug-In for Foreman's Smart Proxy

LICENSE=	GPLv3

RUN_DEPENDS=	foreman-proxy>=1.8.0:${PORTSDIR}/net/foreman-proxy \
		rubygem-chef-api>0:${PORTSDIR}/sysutils/rubygem-chef-api

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d
		${INSTALL_DATA} ${WRKSRC}/settings.d/chef.yml.example \
			${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/chef.yml.sample
		${MKDIR} ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
		${INSTALL_DATA} ${WRKSRC}/bundler.d/chef.rb \
			${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/chef.rb

.include <bsd.port.mk>
