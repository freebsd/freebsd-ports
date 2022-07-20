PORTNAME=	foreman-proxy
PORTVERSION=	3.1.2
CATEGORIES=	net
MASTER_SITES=	https://downloads.theforeman.org/foreman-proxy/

MAINTAINER=	freebsd@moov.de
COMMENT=	Foreman Proxy Agent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler_ext>=0.4:sysutils/rubygem-bundler_ext \
		rubygem-concurrent-ruby>=1.0:devel/rubygem-concurrent-ruby \
		rubygem-json>=1.8.1:devel/rubygem-json \
		rubygem-logging>=0:devel/rubygem-logging \
		rubygem-rack>=2.0:www/rubygem-rack \
		rubygem-rb-kqueue>=0.2.2:devel/rubygem-rb-kqueue \
		rubygem-rsec>=0.4.3:devel/rubygem-rsec \
		rubygem-sd_notify>=0.1.1:devel/rubygem-sd_notify \
		rubygem-sinatra>=2.0:www/rubygem-sinatra \
		curl:ftp/curl

USES=		shebangfix tar:bzip2

OPTIONS_DEFINE=	BMC PUPPET7
BMC_DESC=	Depend on rubyipmi and redfish_client for BMC support
PUPPET7_DESC=	Depend on Puppet 7

NO_ARCH=	yes
NO_BUILD=	yes
USE_RC_SUBR=	foreman-proxy
USE_RUBY=	yes

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

SHEBANG_FILES=	extra/foreman-debug-proxy

BMC_RUN_DEPENDS=	rubygem-rubyipmi>=0.10.0:sysutils/rubygem-rubyipmi \
			rubygem-redfish_client>=0.5.1:sysutils/rubygem-redfish_client
PUPPET7_RUN_DEPENDS=	puppet:sysutils/puppet7 \
			rubygem-ruby-augeas>=0.5:textproc/rubygem-ruby-augeas

post-patch:
	@${REINPLACE_CMD} \
		-e "s|/usr/bin/env ruby|${RUBY}|g" \
		-e "s|/usr/bin/ruby|${RUBY}|g" \
		-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%DATADIR%%|${DATADIR}|g" \
		${WRKSRC}/bin/smart-proxy \
		${WRKSRC}/extra/dhcpd_config_check.rb \
		${WRKSRC}/extra/foreman-debug-proxy \
		${WRKSRC}/extra/migrate_settings.rb \
		${WRKSRC}/extra/puppet_sign.rb \
		${WRKSRC}/extra/query.rb \
		${WRKSRC}/extra/register_service.rb
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/config/settings.d/*.yml.example \
		${WRKSRC}/lib/proxy/http_download.rb

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d
	${MKDIR} ${STAGEDIR}${DATADIR}/extra
	${LN} -s ${PREFIX}/etc/foreman-proxy ${STAGEDIR}${DATADIR}/config
	${INSTALL_SCRIPT} ${WRKSRC}/bin/smart-proxy \
		${STAGEDIR}${PREFIX}/sbin/smart-proxy
.for file in CHANGELOG Contributors Gemfile LICENSE README.md \
	smart_proxy.gemspec VERSION bundler.d config.ru lib modules
	${CP} -r ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
	${LN} -s Gemfile ${STAGEDIR}${DATADIR}/Gemfile.in
.for script in dhcpd_config_check.rb foreman-debug-proxy \
	migrate_settings.rb puppet_sign.rb query.rb register_service.rb
	${INSTALL_SCRIPT} ${WRKSRC}/extra/${script} \
		${STAGEDIR}${DATADIR}/extra/${script}
.endfor
	${CP} -r ${WRKSRC}/extra/migrations ${STAGEDIR}${DATADIR}/extra
	${INSTALL_DATA} ${WRKSRC}/config/settings.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.yml.sample
.for cfg in bmc dhcp_isc dhcp_libvirt dhcp_native_ms dhcp dns_dnscmd \
	dns_libvirt dns_nsupdate_gss dns_nsupdate dns facts httpboot \
	logs puppet_proxy_puppet_api puppet \
	puppetca_hostname_whitelisting puppetca_http_api \
	puppetca_puppet_cert puppetca_token_whitelisting \
	puppetca realm_freeipa realm registration templates tftp
	${INSTALL_DATA} ${WRKSRC}/config/settings.d/${cfg}.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/${cfg}.yml.sample
.endfor
	${MKDIR} -m 0700 ${STAGEDIR}${FOREMAN_PROXY_LOGDIR} \
		${STAGEDIR}${FOREMAN_PROXY_RUNDIR}

.include <bsd.port.mk>
