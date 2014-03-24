# Created by: Tomoyuki Sakurai <cherry@trombik.mine.nu>
# $FreeBSD$

PORTNAME=	puppet
PORTVERSION=	3.4.3
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.puppetlabs.com/puppet/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-facter>=0:${PORTSDIR}/sysutils/rubygem-facter \
		rubygem-ruby-augeas>=0:${PORTSDIR}/textproc/rubygem-augeas \
		rubygem-hiera>=0:${PORTSDIR}/sysutils/rubygem-hiera

CONFLICTS=	puppet-2*
NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RC_SUBR=	puppet puppetmaster
PORTDOCS=	LICENSE README.md
PORTEXAMPLES=	*
USERS=		puppet
GROUPS=		puppet
SUB_FILES+=	pkg-message
SUB_LIST=	RUBY=${RUBY}
PLIST_SUB+=	RESETPREFIX=${PREFIX}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	PACKAGE_ORIGIN
OPTIONS_SINGLE=		PATCHES
OPTIONS_SINGLE_PATCHES=	PACKAGE_ORIGIN PACKAGE_ROOT
PACKAGE_ORIGIN_DESC=	Use port origin as package name
PACKAGE_ROOT_DESC=	Use PACKAGEROOT instead of PACKAGESITE
PATCHES_DESC=		Optional exclusive patches

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPACKAGE_ROOT}
.if ! ${PORT_OPTIONS:MPACKAGE_ORIGIN}
EXTRA_PATCHES+=	${FILESDIR}/optpatch-package_root
.else
BROKEN=	PACKAGE_ROOT option patch is incompatable with PACKAGE_ORIGIN patch.
.endif
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPACKAGE_ORIGIN}
EXTRA_PATCHES+=	${FILESDIR}/optpatch-package_origin
RUN_DEPENDS+=	rubygem-bzip2>=0:${PORTSDIR}/archivers/rubygem-bzip2
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/puppet|${ETCDIR}|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/defaults.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/var/lib/puppet|/var/puppet|" \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|\$$vardir/run|/var/run/puppet|" \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|\$$confdir/ssl|/var/puppet/ssl|" \
		${WRKSRC}/lib/puppet/defaults.rb
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/ext/rack/config.ru

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb --no-configs --destdir=${STAGEDIR}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/modules
	${MKDIR} ${STAGEDIR}/var/puppet
	${INSTALL_DATA} ${WRKSRC}/conf/auth.conf ${STAGEDIR}${ETCDIR}/auth.conf-dist
	${RUBY} -I ${STAGEDIR}/${RUBY_SITELIBDIR} ${STAGEDIR}${PREFIX}/bin/puppet master --genconfig \
		--confdir=${ETCDIR} \
		--rundir=/var/run/puppet \
		--vardir=/var/puppet \
		--logdir=/var/log/puppet \
		> ${STAGEDIR}${ETCDIR}/puppet.conf-dist
	@${ECHO} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet.rb | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO} ${STAGEDIR}${RUBY_SITELIBDIR}/semver.rb | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/public
	${INSTALL_DATA} ${WRKSRC}/ext/rack/config.ru ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/rack/example-passenger-vhost.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
