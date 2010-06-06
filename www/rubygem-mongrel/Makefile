# Ports collection makefile for:	mongrel
# Date created:				20 May 2006
# Whom:					Rui Lopes (<rgl ruilopes com>)
#
# $FreeBSD$

PORTNAME=	mongrel
PORTVERSION=	1.1.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG
DISTFILES=	${PATCHNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Fast HTTP 1.1 library and server for Ruby web applications

RUN_DEPENDS=	gpgen:${PORTSDIR}/devel/rubygem-gem_plugin \
		rubygem-daemons>=1.0.3:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-fastthread>=1.0.1:${PORTSDIR}/devel/rubygem-fastthread

USE_RUBY=	yes
USE_RUBYGEMS=	yes

PATCHNAME=	cgi_multipart_eof_fix-2.5.0
PLIST_SUB=	CGIFIX="${PATCHNAME}"

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

.include <bsd.port.mk>
