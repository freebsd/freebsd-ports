# $FreeBSD$

PORTNAME=	puppet
PORTVERSION=	5.5.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://downloads.puppetlabs.com/puppet/
PKGNAMESUFFIX=	5

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to install: Could not load facter; cannot install

BUILD_DEPENDS=	rubygem-hiera>=2.0:sysutils/rubygem-hiera \
		rubygem-json_pure>=0:devel/rubygem-json_pure
RUN_DEPENDS=	rubygem-gettext-setup>=0:devel/rubygem-gettext-setup \
		rubygem-hiera>=2.0:sysutils/rubygem-hiera \
		rubygem-hocon>=0:devel/rubygem-hocon \
		rubygem-json_pure>=0:devel/rubygem-json_pure \
		rubygem-ruby-augeas>=0:textproc/rubygem-ruby-augeas

USES=		cpe
CPE_VENDOR=	puppetlabs
CONFLICTS_INSTALL=	puppet4-* puppet6-*
NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	puppet puppetmaster
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

RFACTER_DESC=	Use facter 2.x (written in Ruby)
CFACTER_DESC=	Use facter 3.x (experimental rewrite in C++)

RFACTER_BUILD_DEPENDS=	rubygem-facter>=2.0:sysutils/rubygem-facter
RFACTER_RUN_DEPENDS=	rubygem-facter>=2.0:sysutils/rubygem-facter

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
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/ext/rack/config.ru

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
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/rack/config.ru ${STAGEDIR}${WWWDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/rack/example-passenger-vhost.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
