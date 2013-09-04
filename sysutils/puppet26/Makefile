# Created by:	Tomoyuki Sakurai <cherry@trombik.mine.nu>
# $FreeBSD$

PORTNAME=	puppet
PORTVERSION=	2.6.18
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.puppetlabs.com/puppet/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A configuration management framework written in Ruby

DEPRECATED=	End of Life from april 2013. Upgrade to 2.7 or 3.x.
EXPIRATION_DATE=	2013-10-01

RUN_DEPENDS=	rubygem-facter>=0:${PORTSDIR}/sysutils/rubygem-facter \
		rubygem-ruby-augeas>=0:${PORTSDIR}/textproc/rubygem-augeas \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv

LATEST_LINK=	puppet26
CONFLICTS=	puppet-2.7.* puppet-3.*

NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	puppet puppetmaster
PORTDOCS=	CHANGELOG README.md README.queueing LICENSE COPYING
PORTEXAMPLES=	*
PUPPET_USER:=	puppet
PUPPET_GROUP:=	${PUPPET_USER}
PUPPET_VARDIR:=	/var/${PORTNAME}
PUPPET_RUNDIR:=	/var/run/${PORTNAME}
SUB_FILES+=	pkg-install pkg-message pkg-deinstall
SUB_LIST+=	PUPPET_USER="${PUPPET_USER}" \
		PUPPET_GROUP="${PUPPET_GROUP}" \
		PUPPET_VARDIR="${PUPPET_VARDIR}" \
		PUPPET_RUNDIR="${PUPPET_RUNDIR}"

MANCOMPRESSED=	yes
MAN5=	puppet.conf.5
MAN8=	filebucket.8 pi.8 puppet.8 puppetca.8 puppetd.8 \
	puppetdoc.8 puppetmasterd.8 puppetrun.8 ralsh.8 puppetqd.8

OPTIONS_DEFINE=	MONGREL PACKAGE_ORIGIN DOCS EXAMPLES
OPTIONS_DEFAULT=	PACKAGE_ORIGIN
MONGREL_DESC=		Run puppet server as a mongrel service
PACKAGE_ORIGIN_DESC=	Use port origin as package name

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMONGREL}
RUN_DEPENDS+=	rubygem-mongrel>=0:${PORTSDIR}/www/rubygem-mongrel
.endif

.if ${PORT_OPTIONS:MPACKAGE_ORIGIN}
EXTRA_PATCHES+=	${FILESDIR}/optpatch-package_origin
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/bz2.so:${PORTSDIR}/archivers/ruby-bz2
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/puppet|${ETCDIR}|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/defaults.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/var/lib/puppet|${PUPPET_VARDIR}|" \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|\$$vardir/run|${PUPPET_RUNDIR}|" \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|\$$confdir/ssl|${PUPPET_VARDIR}/ssl|" \
		${WRKSRC}/lib/puppet/defaults.rb

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb --no-configs

post-install:
	${INSTALL} -d ${ETCDIR}
	${INSTALL} -m 0644 ${WRKSRC}/conf/auth.conf ${ETCDIR}/auth.conf-dist
	${RUBY} -I ${RUBY_SITELIBDIR} ${PREFIX}/sbin/puppetmasterd \
		--confdir=${ETCDIR} \
		--rundir=${PUPPET_RUNDIR} \
		--genconfig | \
		${SED} -e 's/genconfig = true/# genconfig = false/' \
		> ${ETCDIR}/puppet.conf-dist
	@${ECHO} ${RUBY_SITELIBDIR}/puppet.rb | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
