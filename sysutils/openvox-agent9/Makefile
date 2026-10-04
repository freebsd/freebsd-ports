PORTNAME=	openvox-agent
DISTVERSION=	9.0.0
CATEGORIES=	sysutils
MASTER_SITES=   https://forge.puppet.com/v3/files/:forge
PKGNAMESUFFIX=	9

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby
WWW=		https://github.com/OpenVoxProject/openvox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0.1<0.4:converters/rubygem-base64 \
		rubygem-benchmark>=0.1<0.6:benchmarks/rubygem-benchmark \
		rubygem-concurrent-ruby>1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-deep_merge>1.0<2:devel/rubygem-deep_merge \
		rubygem-fast_gettext>=2.1<5:devel/rubygem-fast_gettext \
		rubygem-getoptlong>=0.2.0<0.3:devel/rubygem-getoptlong \
		rubygem-locale>=2.1<3.0:devel/rubygem-locale \
		rubygem-openfact>=6.0.0<7:sysutils/rubygem-openfact \
		rubygem-ostruct>=0.6.0<0.7:devel/rubygem-ostruct \
		rubygem-puppet-resource_api>=2.0<3:devel/rubygem-puppet-resource_api \
		rubygem-racc>=1.5<2:devel/rubygem-racc \
		rubygem-ruby-augeas>=0:textproc/rubygem-ruby-augeas \
		rubygem-scanf>=1.0<2:devel/rubygem-scanf \
		rubygem-semantic_puppet>=1.0<2:devel/rubygem-semantic_puppet
# Ruby 3.4 support
RUN_DEPENDS+=	rubygem-syslog>=0.3:devel/rubygem-syslog

USES=		cpe ruby
USE_GITHUB=	yes
GH_ACCOUNT=	OpenVoxProject
GH_PROJECT=	openvox

CONFLICTS_INSTALL=	openvox-agent[0-9] puppet[0-9]
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
NO_ARCH=	yes
NO_BUILD=	yes
USE_RC_SUBR=	puppet
PORTDOCS=	LICENSE README.md
PORTEXAMPLES=	*
USERS=		puppet
GROUPS=		puppet
SUB_FILES+=	pkg-message
SUB_LIST=	RUBY=${RUBY}

DATADIR=	${PREFIX}/share/puppet
ETCDIR=		${PREFIX}/etc/puppet

OPTIONS_DEFINE=		DOCS EXAMPLES

# Get versions from
# https://github.com/OpenVoxProject/openvox/tree/main/packaging/configs/components
# for f in packaging/configs/components/module-puppetlabs-*.json; do echo "${${f#*/module-puppetlabs-}%.json}=${$(jq -r .ref $f)#*v}"; done
FORGE_MODULES=	augeas_core=2.0.1 \
		cron_core=2.0.2 \
		host_core=2.0.1 \
		mount_core=1.3.0 \
		scheduled_task=5.0.0 \
		selinux_core=2.0.1 \
		sshkeys_core=3.0.2 \
		yumrepo_core=3.0.1 \
		zfs_core=2.0.1

.for module in ${FORGE_MODULES}
DISTFILES+=	puppetlabs-${module:C/=.*//}-${module:C/.*=//}.tar.gz:forge
.endfor

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/puppetlabs/puppet|${ETCDIR}|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/etc/puppetlabs/code|${ETCDIR}|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/opt/puppetlabs/puppet/cache|/var/puppet|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/var/run/puppetlabs|/var/run/puppet|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/var/log/puppetlabs/puppet|/var/log/puppet|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/opt/puppetlabs/puppet/public|/var/puppet/state|" \
		-e "s|/opt/puppetlabs/puppet/modules|${ETCDIR}/vendor_modules|" \
		-e "s|/opt/puppetlabs/puppet/vendor_modules|${ETCDIR}/vendor_modules|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/opt/puppetlabs/puppet/modules|${ETCDIR}/modules|" \
		-e "s|/etc/puppetlabs/puppetserver/ca|/var/puppetserver/ca|" \
		${WRKSRC}/lib/puppet/defaults.rb
	@${REINPLACE_CMD} -e "s|/opt/puppetlabs/puppet/bin/gem|${LOCALBASE}/bin/gem|" \
		${WRKSRC}/lib/puppet/provider/package/puppet_gem.rb
	@${REINPLACE_CMD} -e "s|\$$confdir/ssl|/var/puppet/ssl|" \
		${WRKSRC}/lib/puppet/defaults.rb
	@${REINPLACE_CMD} -e "s|\.\./\.\./\.\./locales|../locales|" \
		${WRKSRC}/lib/puppet/gettext/config.rb

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb --no-configs --destdir=${STAGEDIR} \
		--localedir=${RUBY_SITELIBDIR}/puppet/locales --publicdir=/var/puppet/state/

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/manifests
	${MKDIR} ${STAGEDIR}${ETCDIR}/modules
	${MKDIR} ${STAGEDIR}${ETCDIR}/vendor_modules
.for module in ${FORGE_MODULES}
	(cd ${WRKDIR}/puppetlabs-${module:C/=.*//}-${module:C/.*=//} && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/vendor_modules/${module:C/=.*//})
.endfor
	${MKDIR} ${STAGEDIR}/var/puppet
	${RUBY} -I ${STAGEDIR}/${RUBY_SITELIBDIR} ${STAGEDIR}${PREFIX}/bin/puppet agent --genconfig \
		--confdir=${ETCDIR} \
		--rundir=/var/run/puppet \
		--vardir=/var/puppet \
		--logdir=/var/log/puppet \
		--codedir=${ETCDIR} \
		> ${STAGEDIR}${ETCDIR}/puppet.conf-dist
	@${ECHO} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet.rb | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet -type f | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/specifications
	${RUBY} -e "puts Gem::Specification.load('${WRKSRC}/openvox.gemspec').to_ruby" > ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/specifications/openvox-${PORTVERSION}.gemspec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
