PORTNAME=	smart_proxy_dynflow
PORTVERSION=	0.9.3
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Plugin to use Dynflow in Foreman Smart Proxy
WWW=		https://github.com/theforeman/smart_proxy_dynflow

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	foreman-proxy>=1.12.0:net/foreman-proxy \
		rubygem-dynflow>=1.6<2:devel/rubygem-dynflow \
		rubygem-rest-client>=2.0<3:www/rubygem-rest-client \
		rubygem-sqlite31>=1.0<2:databases/rubygem-sqlite31

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	"@sample etc/foreman-proxy/settings.d/dynflow.yml.sample" \
		share/foreman-proxy/bundler.d/dynflow.rb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/settings.d/dynflow.yml.example ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/dynflow.yml.sample
	${INSTALL_DATA} ${WRKSRC}/bundler.d/dynflow.rb ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/dynflow.rb

.include <bsd.port.mk>
