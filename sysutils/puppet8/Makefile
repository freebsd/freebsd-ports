PORTNAME=	puppet
PORTVERSION=	8.10.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=   https://forge.puppet.com/v3/files/:forge
PKGNAMESUFFIX=	8

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby
WWW=		https://puppet.com/docs/puppet/latest/puppet_index.html

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>1.0:devel/rubygem-concurrent-ruby \
		rubygem-deep_merge>1.0:devel/rubygem-deep_merge \
		rubygem-facter>=4.3.0:sysutils/rubygem-facter \
		rubygem-fast_gettext>=2.1:devel/rubygem-fast_gettext \
		rubygem-getoptlong>=0.2.0:devel/rubygem-getoptlong \
		rubygem-locale>=2.1:devel/rubygem-locale \
		rubygem-multi_json>=1.13:devel/rubygem-multi_json \
		rubygem-puppet-resource_api>=1.5:devel/rubygem-puppet-resource_api \
		rubygem-ruby-augeas>=0:textproc/rubygem-ruby-augeas \
		rubygem-scanf>=1.0:devel/rubygem-scanf \
		rubygem-semantic_puppet>=1.0:devel/rubygem-semantic_puppet

USES=		cpe ruby
USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

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

OPTIONS_DEFINE=		DOCS EXAMPLES

# Get versions from
# https://github.com/puppetlabs/puppet-agent/tree/main/configs/components
# for f in configs/components/module-puppetlabs-*.json; do echo ${${f#*/module-puppetlabs-}%.json}=${${$(jq .ref $f)#*/v}%\"}; done
FORGE_MODULES=	augeas_core=1.5.0 \
		cron_core=1.3.0 \
		host_core=1.3.0 \
		mount_core=1.3.0 \
		scheduled_task=3.2.0 \
		selinux_core=1.4.0 \
		sshkeys_core=2.5.0 \
		yumrepo_core=2.1.0 \
		zfs_core=1.5.0 \
		zone_core=1.2.0

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
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} LC_ALL=C.UTF-8 ${RUBY} ${WRKSRC}/install.rb --no-configs --destdir=${STAGEDIR} \
		--localedir=${RUBY_SITELIBDIR}/puppet/locales --publicdir=/var/puppet/state/

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/manifests
	${MKDIR} ${STAGEDIR}${ETCDIR}/modules
	${MKDIR} ${STAGEDIR}${ETCDIR}/vendor_modules
.for module in ${FORGE_MODULES}
	(cd ${WRKDIR}/puppetlabs-${module:C/=.*//}-${module:C/.*=//} && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/vendor_modules/${module:C/=.*//})
.endfor
	${MKDIR} ${STAGEDIR}/var/puppet
	${SETENV} LC_ALL=C.UTF-8 ${RUBY} -I ${STAGEDIR}/${RUBY_SITELIBDIR} ${STAGEDIR}${PREFIX}/bin/puppet agent --genconfig \
		--confdir=${ETCDIR} \
		--rundir=/var/run/puppet \
		--vardir=/var/puppet \
		--logdir=/var/log/puppet \
		--codedir=${ETCDIR} \
		> ${STAGEDIR}${ETCDIR}/puppet.conf-dist
	@${ECHO} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet.rb | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/specifications
	${INSTALL_DATA} ${WRKSRC}/puppet.gemspec ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/specifications/${PORTNAME}-${PORTVERSION}.gemspec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
