# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	smart_proxy_salt
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SaltStack Plug-In for Foreman's Smart Proxy

LICENSE=	GPLv3

RUN_DEPENDS=	foreman-proxy>=1.8.0:net/foreman-proxy \
		${PYTHON_PKGNAMEPREFIX}salt>0:sysutils/py-salt

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem python

post-patch:
		@${REINPLACE_CMD} \
			-e "s|/usr/bin/env ruby|${RUBY}|g" \
			-e "s|/usr/bin/env python|${PYTHON_CMD}|g" \
			-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
			${WRKSRC}/bin/foreman-node \
			${WRKSRC}/sbin/upload-salt-reports

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d
		${INSTALL_DATA} ${WRKSRC}/settings.d/salt.yml.example \
			${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/salt.yml.sample
		${MKDIR} ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
		${INSTALL_DATA} ${FILESDIR}/salt.rb \
			${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/salt.rb
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/salt
		${INSTALL_DATA} ${WRKSRC}/etc/foreman.yaml.example \
			${STAGEDIR}${PREFIX}/etc/salt/foreman.yaml.sample
		${INSTALL_SCRIPT} ${WRKSRC}/sbin/upload-salt-reports \
			${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
