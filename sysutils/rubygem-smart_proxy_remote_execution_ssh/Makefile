# $FreeBSD$

PORTNAME=	smart_proxy_remote_execution_ssh
PORTVERSION=	0.0.13
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SSH remote execution provider for foreman-proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	foreman-proxy>=1.9.0:net/foreman-proxy \
		rubygem-net-scp>=0:security/rubygem-net-scp \
		rubygem-net-ssh>=0:security/rubygem-net-ssh \
		rubygem-smart_proxy_dynflow>=0.0.3:sysutils/rubygem-smart_proxy_dynflow

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	"@sample etc/foreman-proxy/settings.d/remote_execution_ssh.yml.sample" \
		share/foreman-proxy/bundler.d/remote_execution_ssh.rb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/settings.d/remote_execution_ssh.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/remote_execution_ssh.yml.sample
	${INSTALL_DATA} ${WRKSRC}/bundler.d/remote_execution_ssh.rb \
		${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/remote_execution_ssh.rb

.include <bsd.port.mk>
