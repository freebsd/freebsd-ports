PORTNAME=	smart_proxy_remote_execution_ssh
PORTVERSION=	0.11.6
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SSH remote execution provider for foreman-proxy
WWW=		https://github.com/theforeman/smart_proxy_remote_execution_ssh

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	foreman-proxy>=1.12.0:net/foreman-proxy \
		rubygem-bcrypt_pbkdf>=1.0<2.0:security/rubygem-bcrypt_pbkdf \
		rubygem-ed25519>=1.2<2.0:security/rubygem-ed25519 \
		rubygem-mqtt>=0.5<1:net/rubygem-mqtt \
		rubygem-net-ssh>=7.2,2<8,2:security/rubygem-net-ssh \
		rubygem-smart_proxy_dynflow>=0.9.4<1:sysutils/rubygem-smart_proxy_dynflow

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	"@sample etc/foreman-proxy/settings.d/remote_execution_ssh.yml.sample" \
		share/foreman-proxy/bundler.d/remote_execution_ssh.rb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/settings.d/remote_execution_ssh.yml.example ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/remote_execution_ssh.yml.sample
	${INSTALL_DATA} ${WRKSRC}/bundler.d/remote_execution_ssh.rb ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/remote_execution_ssh.rb

.include <bsd.port.mk>
