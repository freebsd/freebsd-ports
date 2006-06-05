# Ports collection makefile for:	mongrel
# Date created:				20 May 2006
# Whom:					Rui Lopes (<rgl ruilopes com>)
#
# $FreeBSD$

PORTNAME=	mongrel
PORTVERSION=	0.3.12.4
CATEGORIES=	www rubygems
MASTER_SITES=	http://rubyforge.org/frs/download.php/9700/

MAINTAINER=	rgl@ruilopes.com
COMMENT=	Fast HTTP 1.1 library and server for Ruby web applications

BUILD_DEPENDS=	gpgen:${PORTSDIR}/devel/rubygem-gem_plugin \
		rubygem-daemons>=0.4.4:${PORTSDIR}/devel/rubygem-daemons
RUN_DEPENDS=	${BUILD_DEPENDS}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,^${CACHE_DIR}(/.+)$$,%%CACHE_DIR%%\1,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${SPEC_DIR}(/.+)$$,%%SPEC_DIR%%\1,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
