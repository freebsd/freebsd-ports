# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	smart_proxy_salt
PORTVERSION=	1.0.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	SaltStack Plug-In for Foreman's Smart Proxy

LICENSE=	GPLv3

RUN_DEPENDS=	foreman-proxy>=1.6.0:${PORTSDIR}/net/foreman-proxy \
		${PYTHON_PKGNAMEPREFIX}salt>0:${PORTSDIR}/sysutils/py-salt

USES=		python
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

post-patch:
		@${REINPLACE_CMD} \
			-e "s|/usr/bin/env ruby|${RUBY}|g" \
			-e "s|/usr/bin/env python|${PYTHON_CMD}|g" \
			-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
			${WRKSRC}/bin/foreman-node \
			${WRKSRC}/sbin/upload-salt-reports

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d
		${INSTALL_DATA} ${FILESDIR}/salt.yml.sample ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/salt.yml.sample
		${MKDIR} ${STAGEDIR}${PREFIX}/share/foreman-proxy
		${MKDIR} ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
		${INSTALL_DATA} ${FILESDIR}/salt.rb ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/salt.rb
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/salt
		${INSTALL_DATA} ${FILESDIR}/foreman.yaml.sample ${STAGEDIR}${PREFIX}/etc/salt/foreman.yaml.sample
		${INSTALL_SCRIPT} ${WRKSRC}/sbin/upload-salt-reports ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.post.mk>
