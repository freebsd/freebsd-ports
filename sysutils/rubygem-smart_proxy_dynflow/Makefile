# $FreeBSD$

PORTNAME=	smart_proxy_dynflow
PORTVERSION=	0.0.7
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Plugin to use Dynflow in Foreman Smart Proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	foreman-proxy>=1.9.0:net/foreman-proxy \
		rubygem-dynflow>=0.8.4:devel/rubygem-dynflow \
		rubygem-sequel>=0:devel/rubygem-sequel \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	"@sample etc/foreman-proxy/settings.d/dynflow.yml.sample" \
		share/foreman-proxy/bundler.d/dynflow.rb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/settings.d/dynflow.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/dynflow.yml.sample
	${INSTALL_DATA} ${WRKSRC}/bundler.d/dynflow.rb \
		${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/dynflow.rb

.include <bsd.port.mk>
