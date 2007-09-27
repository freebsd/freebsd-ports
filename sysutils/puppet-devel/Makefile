# New ports collection makefile for:	rubygem-puppet
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	puppet
PORTVERSION=	0.23.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.reductivelabs.com/downloads/puppet/
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	cherry@trombik.org
COMMENT=	A configuration management framework written in Ruby

BUILD_DEPENDS=	${RUBY_SITELIBDIR}/facter.rb:${PORTSDIR}/sysutils/facter
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	puppet-[0-9]*

NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	puppetmasterd puppetd

DOCS=	CHANGELOG README LICENSE COPYING

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|/etc/puppet|${PREFIX}/etc/puppet|" \
		${WRKSRC}/lib/puppet/configuration.rb

do-install:
	cd ${WRKSRC} && \
		${SETENV} DSTDIR=${DSTDIR}/${PREFIX} \
		${RUBY} ${WRKSRC}/install.rb --full
	${INSTALL} -d ${DOCSDIR}
.if !defined(NOPORTDOCS)
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	${INSTALL} -d ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

post-install:
	${INSTALL} -d ${PREFIX}/etc/${PORTNAME}
.for DIR in ssl manifests
	${INSTALL} -d ${PREFIX}/etc/${PORTNAME}/${DIR}
.endfor
	${RUBY} -I ${RUBY_SITELIBDIR} ${PREFIX}/bin/puppetmasterd \
		--confdir=${PREFIX}/etc/${PORTNAME} \
		--rundir=/var/run \
		--genconfig | \
		${SED} -e 's/genconfig = true/# genconfig = false/' \
		> ${PREFIX}/etc/${PORTNAME}/puppet.conf-dist
	@${ECHO} ${RUBY_SITELIBDIR}/puppet.rb | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
