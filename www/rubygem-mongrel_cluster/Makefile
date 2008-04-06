# Ports collection makefile for:	mongrel_cluster
# Date created:				20 May 2006
# Whom:					Rui Lopes (<rgl ruilopes com>)
#
# $FreeBSD$

PORTNAME=	mongrel_cluster
PORTVERSION=	1.0.5
CATEGORIES=	www rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	mongrel

MAINTAINER=	ports@logvinov.com
COMMENT=	Manages multiple Mongrel processes

BUILD_DEPENDS=	rubygem-mongrel>=1.0.2:${PORTSDIR}/www/rubygem-mongrel
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RC_SUBR=	mongrel_cluster
USE_RUBY=	yes
USE_RUBYGEMS=	yes
REINPLACE_ARGS=	-i ""

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,.*etc/rc.d/.+$$,,g \
		;s,^${GEM_CACHE}$$,%%GEM_CACHE%%,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${GEM_SPEC}$$,%%GEM_SPEC%%,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

post-install:
	${RMDIR} ${PREFIX}/${GEM_DOC_DIR}
	@${REINPLACE_CMD} -e 's|/usr/bin/env ruby|${RUBY}|' ${PREFIX}/bin/mongrel_cluster_ctl
	@${REINPLACE_CMD} -e 's|mongrel_rails|${PREFIX}/bin/mongrel_rails|g' \
		${PREFIX}/${GEM_LIB_DIR}/bin/mongrel_cluster_ctl
	@${REINPLACE_CMD} -e 's|\"mongrel_rails\"|\"${PREFIX}/bin/mongrel_rails\"|g' \
		${PREFIX}/${GEM_LIB_DIR}/lib/${PORTNAME}/init.rb

.include <bsd.port.mk>
