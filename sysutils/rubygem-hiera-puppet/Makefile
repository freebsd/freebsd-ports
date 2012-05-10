# Ports collection makefile for:	hiera-puppet
# Date created:				10 May 2012
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hiera-puppet
PORTVERSION=	0.3.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A data backend for Hiera that queries the Puppet scope for data

RUN_DEPENDS=	puppet:${PORTSDIR}/sysutils/puppet \
		rubygem-hiera:${PORTSDIR}/sysutils/rubygem-hiera

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
HIERA_DBDIR=	/var/db/hiera

dummy-post-install:
	@${REINPLACE_CMD} "s!/etc/hiera.yaml!${PREFIX}/etc/hiera.yaml!" \
		${PREFIX}/${GEM_LIB_DIR}/bin/hiera \
		${PREFIX}/${GEM_LIB_DIR}/lib/hiera.rb \
		${PREFIX}/${GEM_LIB_DIR}/spec/unit/hiera_spec.rb
	@${REINPLACE_CMD} "s!/var/lib/hiera!${HIERA_DBDIR}!" \
		${PREFIX}/${GEM_LIB_DIR}/lib/hiera/backend.rb \
		${PREFIX}/${GEM_LIB_DIR}/spec/unit/backend_spec.rb
	@${MKDIR} ${HIERA_DBDIR}
	@${ECHO_CMD} '@cwd /' >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${MKDIR} ${HIERA_DBDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} \"%D/${HIERA_DBDIR}\" 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} '@cwd' >> ${TMPPLIST}

.include <bsd.port.mk>
