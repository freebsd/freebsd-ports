# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foreman-proxy
PORTVERSION=	1.6.2
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Foreman Proxy Agent

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-bundler_ext>=0.4:${PORTSDIR}/sysutils/rubygem-bundler_ext \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-rack>=1.1:${PORTSDIR}/www/rubygem-rack \
		rubygem-sinatra>=1.4.3:${PORTSDIR}/www/rubygem-sinatra \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

OPTIONS_DEFINE=	BMC PUPPET
BMC_DESC=	Depend on rubyipmi for BMC support
PUPPET_DESC=	Depend on Puppet

USE_GITHUB=	yes
GH_ACCOUNT=	theforeman
GH_PROJECT=	smart-proxy
GH_COMMIT=	b53b4d0
USE_RUBY=	yes
USE_RAKE=	yes
USE_RC_SUBR=	foreman-proxy
NO_BUILD=	yes
NO_ARCH=	yes

FOREMAN_PROXY_USER?=	foreman_proxy
FOREMAN_PROXY_GROUP?=	foreman_proxy
FOREMAN_PROXY_LOGDIR?=	/var/log/foreman-proxy
FOREMAN_PROXY_RUNDIR?=	/var/run/foreman-proxy

USERS=		${FOREMAN_PROXY_USER}
GROUPS=		${FOREMAN_PROXY_GROUP}

SUB_LIST=	RUBY="${RUBY}" \
		FOREMAN_PROXY_USER="${FOREMAN_PROXY_USER}" \
		FOREMAN_PROXY_GROUP="${FOREMAN_PROXY_GROUP}" \
		FOREMAN_PROXY_RUNDIR="${FOREMAN_PROXY_RUNDIR}" \
		FOREMAN_PROXY_LOGDIR="${FOREMAN_PROXY_LOGDIR}"

PLIST_SUB=	${SUB_LIST} MKDIR="${MKDIR}"

BMC_RUN_DEPENDS=	rubygem-rubyipmi>=0.7:${PORTSDIR}/sysutils/rubygem-rubyipmi
PUPPET_RUN_DEPENDS=	puppet:${PORTSDIR}/sysutils/puppet \
			rubygem-ruby-augeas>=0.5:${PORTSDIR}/textproc/rubygem-augeas

post-patch:
	@${REINPLACE_CMD} \
		-e "s|/usr/bin/env ruby|${RUBY}|g" \
		-e "s|/usr/bin/ruby|${RUBY}|g" \
		-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%DATADIR%%|${DATADIR}|g" \
		${WRKSRC}/bin/smart-proxy \
		${WRKSRC}/extra/migrate_settings.rb \
		${WRKSRC}/extra/query.rb
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/config/settings.d/*.yml.example \
		${WRKSRC}/lib/proxy/http_downloads.rb

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d
	${MKDIR} ${STAGEDIR}${DATADIR}/extra
	${LN} -s ${PREFIX}/etc/foreman-proxy ${STAGEDIR}${DATADIR}/config
	${INSTALL_SCRIPT} ${WRKSRC}/bin/smart-proxy \
		${STAGEDIR}${PREFIX}/sbin/smart-proxy
.for file in CHANGELOG Contributors Gemfile LICENSE README Rakefile \
	VERSION bundler.d config.ru lib modules public views
	${CP} -r ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
	${LN} -s Gemfile ${STAGEDIR}${DATADIR}/Gemfile.in
.for script in migrate_settings.rb query.rb
	${INSTALL_SCRIPT} ${WRKSRC}/extra/${script} \
		${STAGEDIR}${DATADIR}/extra/${script}
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/settings.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.yml.sample
.for cfg in bmc chef dhcp dns puppet puppetca realm tftp
	${INSTALL_DATA} ${WRKSRC}/config/settings.d/${cfg}.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/${cfg}.yml.sample
.endfor
	${MKDIR} -m 0700 ${STAGEDIR}${FOREMAN_PROXY_LOGDIR} \
		${STAGEDIR}${FOREMAN_PROXY_RUNDIR}

.include <bsd.port.mk>
