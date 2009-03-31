# New ports collection makefile for:	rubygem-puppet
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	puppet
PORTVERSION=	0.24.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.reductivelabs.com/downloads/puppet/
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	cherry@trombik.org
COMMENT=	A configuration management framework written in Ruby

BUILD_DEPENDS=	${RUBY_SITELIBDIR}/facter.rb:${PORTSDIR}/sysutils/facter \
	portupgrade>0:${PORTSDIR}/ports-mgmt/portupgrade
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=	Use sysutils/puppet instead
EXPIRATION_DATE=	2009-04-30
CONFLICTS=	puppet-[0-9]*

NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	puppetmasterd puppetd
PORTDOCS=	CHANGELOG README LICENSE COPYING
PORTEXAMPLES=	*
PUPPET_USER:=	puppet
PUPPET_GROUP:=	${PUPPET_USER}
PUPPET_RUNDIR:=	/var/run/${PORTNAME}
PUPPET_WORKDIR:=	/var/${PORTNAME}
SUB_FILES+=	pkg-install pkg-message pkg-deinstall
SUB_LIST+=	PUPPET_RUNDIR="${PUPPET_RUNDIR}" \
			PUPPET_USER="${PUPPET_USER}" \
			PUPPET_GROUP="${PUPPET_GROUP}" \
			PUPPET_WORKDIR="${PUPPET_WORKDIR}"

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|/etc/puppet|${PREFIX}/etc/puppet|" \
		${WRKSRC}/lib/puppet/reference/configuration.rb
	${REINPLACE_CMD} -e "s|/etc/puppet|${PREFIX}/etc/puppet|" \
	${WRKSRC}/lib/puppet/defaults.rb

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb

post-install:
	${INSTALL} -d ${PREFIX}/etc/${PORTNAME}
.for DIR in ssl manifests
	${INSTALL} -d ${PREFIX}/etc/${PORTNAME}/${DIR}
.endfor
	${RUBY} -I ${RUBY_SITELIBDIR} ${PREFIX}/bin/puppetmasterd \
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
