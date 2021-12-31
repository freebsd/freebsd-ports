# Created by: Michael Moll <ruby@FreeBSD.org>

PORTNAME=	smart_proxy_chef
PORTVERSION=	0.2.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Chef Plug-In for Foreman\'s Smart Proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired sysutils/rubygem-chef-api
EXPIRATION_DATE=2022-03-31

RUN_DEPENDS=	foreman-proxy>=1.8.0:net/foreman-proxy \
		rubygem-chef-api>=0:sysutils/rubygem-chef-api

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	"@sample etc/foreman-proxy/settings.d/chef.yml.sample" \
		share/foreman-proxy/bundler.d/chef.rb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/bundler.d/chef.rb ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/chef.rb
	${INSTALL_DATA} ${WRKSRC}/settings.d/chef.yml.example ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/chef.yml.sample

.include <bsd.port.mk>
