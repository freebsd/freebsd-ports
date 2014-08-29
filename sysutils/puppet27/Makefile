# Created by: Tomoyuki Sakurai <cherry@trombik.mine.nu>
# $FreeBSD$

PORTNAME=	puppet
PORTVERSION=	2.7.26
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.puppetlabs.com/puppet/
PKGNAMESUFFIX=	27

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-facter>=0:${PORTSDIR}/sysutils/rubygem-facter \
		rubygem-ruby-augeas>=0:${PORTSDIR}/textproc/rubygem-augeas

LATEST_LINK=	puppet27
CONFLICTS=	puppet-2.6* puppet-3*
NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RC_SUBR=	puppet puppetmaster
PORTDOCS=	CHANGELOG LICENSE README.md
PORTEXAMPLES=	*
USERS=		puppet
GROUPS=		puppet
SUB_FILES+=	pkg-message

PORTSCOUT=	limit:^2\.7\.

MANCOMPRESSED=	yes

OPTIONS_DEFAULT=	PACKAGE_ORIGIN
OPTIONS_SINGLE=		PATCHES
OPTIONS_SINGLE_PATCHES=	PACKAGE_ORIGIN PACKAGE_ROOT
PACKAGE_ORIGIN_DESC=	Use port origin as package name
PACKAGE_ROOT_DESC=	Use PACKAGEROOT insted of PACKAGESITE
PATCHES_DESC=		Optional exclusive patches

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPACKAGE_ORIGIN}
EXTRA_PATCHES+=	${FILESDIR}/optpatch-package_origin
RUN_DEPENDS+=	rubygem-bzip2-ruby>=0:${PORTSDIR}/archivers/rubygem-bzip2-ruby
.endif

.if ${PORT_OPTIONS:MPACKAGE_ROOT}
.if ! ${PORT_OPTIONS:MPACKAGE_ORIGIN}
EXTRA_PATCHES+=	${FILESDIR}/optpatch-package_root
.else
BROKEN=	PACKAGE_ROOT option patch is incompatable with PACKAGE_ORIGIN patch.
.endif
.endif

.include <bsd.port.pre.mk>

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

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb --no-configs --destdir=${STAGEDIR}

post-install:
	${INSTALL} -d ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/puppet
	${MKDIR} ${STAGEDIR}/var/run/puppet
	${INSTALL} -m 0644 ${WRKSRC}/conf/auth.conf ${STAGEDIR}${ETCDIR}/auth.conf-dist
	${RUBY} -I ${STAGEDIR}${RUBY_SITELIBDIR} ${STAGEDIR}${PREFIX}/bin/puppet --genconfig \
		--confdir=${ETCDIR} \
		--rundir=/var/run/puppet | \
		${SED} -e 's/genconfig = true/# genconfig = false/' | \
		${SED} -e 's/factdest =/# factdest =/' \
		> ${STAGEDIR}${ETCDIR}/puppet.conf-dist
	@${ECHO} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet.rb | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO} ${STAGEDIR}${RUBY_SITELIBDIR}/semver.rb | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
