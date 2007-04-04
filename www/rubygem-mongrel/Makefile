# Ports collection makefile for:	mongrel
# Date created:				20 May 2006
# Whom:					Rui Lopes (<rgl ruilopes com>)
#
# $FreeBSD$

PORTNAME=	mongrel
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE} \
    		http://files.rubyforge.mmmultiworks.com/fauna/:PATCH
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PATCHNAME}${EXTRACT_SUFX}:PATCH ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Fast HTTP 1.1 library and server for Ruby web applications

BUILD_DEPENDS=	gpgen:${PORTSDIR}/devel/rubygem-gem_plugin \
		rubygem-daemons>=0.4.4:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-fastthread>=0.6.2:${PORTSDIR}/devel/rubygem-fastthread
RUN_DEPENDS=	${BUILD_DEPENDS}

PATCHNAME=	cgi_multipart_eof_fix-2.1

post-install:
	@${RM} -rf "${PREFIX}/${GEM_LIB_DIR}/ext"

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,^${GEM_CACHE}$$,%%GEM_CACHE%%,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${GEM_SPEC}$$,%%GEM_SPEC%%,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
