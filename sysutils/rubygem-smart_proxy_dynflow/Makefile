PORTNAME=	smart_proxy_dynflow
PORTVERSION=	0.6.1
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Plugin to use Dynflow in Foreman Smart Proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	foreman-proxy>=1.12.0:net/foreman-proxy \
		rubygem-dynflow>=1.6<2:devel/rubygem-dynflow \
		rubygem-rest-client>=0:www/rubygem-rest-client \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	"@sample etc/foreman-proxy/settings.d/dynflow.yml.sample" \
		share/foreman-proxy/bundler.d/dynflow.rb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/settings.d/dynflow.yml.example ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/dynflow.yml.sample
	${INSTALL_DATA} ${WRKSRC}/bundler.d/dynflow.rb ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/dynflow.rb

.include <bsd.port.mk>
