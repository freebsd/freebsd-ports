# $FreeBSD$

PORTNAME=	smart_proxy_remote_execution_ssh
PORTVERSION=	0.0.10
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	SSH remote execution provider for foreman-proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	foreman-proxy>=1.9.0:${PORTSDIR}/net/foreman-proxy \
		rubygem-net-scp>=0:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-ssh>=0:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-smart_proxy_dynflow>=0.0.3:${PORTSDIR}/sysutils/rubygem-smart_proxy_dynflow

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	share/foreman-proxy/bundler.d/remote_execution_ssh.rb \
		"@sample etc/foreman-proxy/settings.d/remote_execution_ssh.yml.sample"

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d
		${INSTALL_DATA} ${WRKSRC}/settings.d/remote_execution_ssh.yml.example \
			${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/remote_execution_ssh.yml.sample
		${MKDIR} ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
		${INSTALL_DATA} ${WRKSRC}/bundler.d/remote_execution_ssh.rb \
			${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/remote_execution_ssh.rb

.include <bsd.port.mk>
