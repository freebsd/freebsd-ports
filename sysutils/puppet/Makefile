# New ports collection makefile for:	rubygem-puppet
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	puppet
PORTVERSION=	2.6.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.puppetlabs.com/downloads/puppet/

MAINTAINER=	raj@csub.edu
COMMENT=	A configuration management framework written in Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/facter.rb:${PORTSDIR}/sysutils/facter \
		rubygem-ruby-augeas>=0:${PORTSDIR}/textproc/rubygem-augeas \
		ruby18-iconv>=0:${PORTSDIR}/converters/ruby-iconv

CONFLICTS=	puppet-devel-[0-9]*

NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	puppet puppetmaster
PORTDOCS=	CHANGELOG README LICENSE COPYING
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

OPTIONS=	MONGREL		"Run puppet server as a mongrel service"	Off

.include <bsd.port.options.mk>

.if defined(WITH_MONGREL)
RUN_DEPENDS+=	rubygem-mongrel>=0:${PORTSDIR}/www/rubygem-mongrel
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/puppet|${PREFIX}/etc/puppet|" \
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
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb

post-install:
	${INSTALL} -d ${PREFIX}/etc/${PORTNAME}
	${RUBY} -I ${RUBY_SITELIBDIR} ${PREFIX}/sbin/puppetmasterd \
		--confdir=${PREFIX}/etc/${PORTNAME} \
		--rundir=${PUPPET_RUNDIR} \
		--genconfig | \
		${SED} -e 's/genconfig = true/# genconfig = false/' \
		> ${PREFIX}/etc/${PORTNAME}/puppet.conf-dist
	@${ECHO} ${RUBY_SITELIBDIR}/puppet.rb | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
