PORTNAME=	puppet
PORTVERSION=	6.23.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	6

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# rubygem-ruby-augeas add again see PR252339, it breaks the installation for some users
# puppet7 does not have it anymore, so users can do a migration to next major version
# without breaking their setup
RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0:devel/rubygem-concurrent-ruby \
		rubygem-deep_merge>=1.0:devel/rubygem-deep_merge \
		rubygem-fast_gettext1>=1.1:devel/rubygem-fast_gettext1 \
		rubygem-ffi>=1.9.24:devel/rubygem-ffi \
		rubygem-hiera>=3.2.1:sysutils/rubygem-hiera \
		rubygem-httpclient>=2.8:www/rubygem-httpclient \
		rubygem-locale>=2.1:devel/rubygem-locale \
		rubygem-multi_json>=1.10:devel/rubygem-multi_json \
		rubygem-puppet-resource_api>=0:devel/rubygem-puppet-resource_api \
		rubygem-semantic_puppet>=1:devel/rubygem-semantic_puppet \
		rubygem-ruby-augeas>=0:textproc/rubygem-ruby-augeas

USES=		cpe
CPE_VENDOR=	puppetlabs
USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

CONFLICTS_INSTALL=	puppet5-* puppet7-*
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	puppet
PORTDOCS=	LICENSE README.md
PORTEXAMPLES=	*
USERS=		puppet
GROUPS=		puppet
SUB_FILES+=	pkg-message
SUB_LIST=	RUBY=${RUBY}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	CFACTER
OPTIONS_RADIO=		FACTER
OPTIONS_RADIO_FACTER=	CFACTER RFACTER

RFACTER_DESC=	Use facter 4.x (future facter, written in Ruby)
CFACTER_DESC=	Use facter 3.x (written in C++)

RFACTER_BUILD_DEPENDS=	rubygem-facter>=4.0:sysutils/rubygem-facter
RFACTER_RUN_DEPENDS=	rubygem-facter>=4.0:sysutils/rubygem-facter

CFACTER_BUILD_DEPENDS=	facter>=3.0:sysutils/facter
CFACTER_RUN_DEPENDS=	facter>=3.0:sysutils/facter

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
	@${REINPLACE_CMD} -e "s|/opt/puppetlabs/puppet/modules|${ETCDIR}/modules|" \
		${WRKSRC}/lib/puppet/defaults.rb
	@${REINPLACE_CMD} -e "s|/opt/puppetlabs/puppet/bin/gem|${LOCALBASE}/bin/gem|" \
		${WRKSRC}/lib/puppet/provider/package/puppet_gem.rb
	@${REINPLACE_CMD} -e "s|\$$confdir/ssl|/var/puppet/ssl|" \
		${WRKSRC}/lib/puppet/defaults.rb
	@${REINPLACE_CMD} -e "s|\.\./\.\./\.\./locales|../locales|" \
		${WRKSRC}/lib/puppet/gettext/config.rb

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} LC_ALL=C.UTF-8 ${RUBY} ${WRKSRC}/install.rb --no-configs --destdir=${STAGEDIR} \
		--localedir=${RUBY_SITELIBDIR}/puppet/locales

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/manifests
	${MKDIR} ${STAGEDIR}${ETCDIR}/modules
	${MKDIR} ${STAGEDIR}/var/puppet
	${INSTALL_DATA} ${WRKSRC}/conf/auth.conf ${STAGEDIR}${ETCDIR}/auth.conf-dist
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
	${INSTALL_DATA} ${WRKSRC}/.gemspec ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/specifications/${PORTNAME}-${PORTVERSION}.gemspec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
