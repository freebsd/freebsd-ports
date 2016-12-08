# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foreman-proxy
PORTVERSION=	1.12.2
CATEGORIES=	net
MASTER_SITES=	http://downloads.theforeman.org/foreman-proxy/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Foreman Proxy Agent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler_ext>=0.4:sysutils/rubygem-bundler_ext \
		rubygem-json>=1.8.1:devel/rubygem-json \
		rubygem-rack16>=1.4:www/rubygem-rack16 \
		rubygem-sinatra>=1.4.3:www/rubygem-sinatra \
		wget:ftp/wget

OPTIONS_DEFINE=	BMC
OPTIONS_RADIO=	PUPPET
OPTIONS_RADIO_PUPPET=	PUPPET3 PUPPET4
BMC_DESC=	Depend on rubyipmi for BMC support
PUPPET3_DESC=	Depend on Puppet 3.8
PUPPET4_DESC=	Depend on Puppet 4

USES=		tar:bzip2
USE_RUBY=	yes
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

BMC_RUN_DEPENDS=	rubygem-rubyipmi>=0.10.0:sysutils/rubygem-rubyipmi
PUPPET3_RUN_DEPENDS=	puppet:sysutils/puppet38 \
			rubygem-ruby-augeas>=0.5:textproc/rubygem-ruby-augeas
PUPPET4_RUN_DEPENDS=	puppet:sysutils/puppet4 \
			rubygem-ruby-augeas>=0.5:textproc/rubygem-ruby-augeas

post-patch:
	@${REINPLACE_CMD} \
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
		${WRKSRC}/lib/proxy/http_download.rb

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d
	${MKDIR} ${STAGEDIR}${DATADIR}/extra
	${LN} -s ${PREFIX}/etc/foreman-proxy ${STAGEDIR}${DATADIR}/config
	${INSTALL_SCRIPT} ${WRKSRC}/bin/smart-proxy \
		${STAGEDIR}${PREFIX}/sbin/smart-proxy
.for file in CHANGELOG Contributors Gemfile LICENSE README.md \
	VERSION bundler.d config.ru lib modules
	${CP} -r ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
	${LN} -s Gemfile ${STAGEDIR}${DATADIR}/Gemfile.in
.for script in migrate_settings.rb query.rb
	${INSTALL_SCRIPT} ${WRKSRC}/extra/${script} \
		${STAGEDIR}${DATADIR}/extra/${script}
.endfor
	${CP} -r ${WRKSRC}/extra/migrations ${STAGEDIR}${DATADIR}/extra
	${INSTALL_DATA} ${WRKSRC}/config/settings.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.yml.sample
.for cfg in bmc dhcp dhcp_isc dhcp_libvirt dhcp_ms_native dns dns_dnscmd \
	dns_libvirt dns_nsupdate dns_nsupdate dns_nsupdate_gss \
	facts logs puppet puppet_proxy_customrun puppet_proxy_legacy \
	puppet_proxy_mcollective puppet_proxy_puppet_api puppet_proxy_puppetrun \
	puppet_proxy_salt puppet_proxy_ssh puppetca realm templates tftp
	${INSTALL_DATA} ${WRKSRC}/config/settings.d/${cfg}.yml.example \
		${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/${cfg}.yml.sample
.endfor
	${MKDIR} -m 0700 ${STAGEDIR}${FOREMAN_PROXY_LOGDIR} \
		${STAGEDIR}${FOREMAN_PROXY_RUNDIR}

.include <bsd.port.mk>
