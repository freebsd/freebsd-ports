# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	1.2.3
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jw@innerewut.de
COMMENT=	MVC web application framework

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		${LOCALBASE}/${SPEC_DIR}/activesupport-1.4.2.gemspec:${PORTSDIR}/devel/rubygem-activesupport \
		${LOCALBASE}/${SPEC_DIR}/activerecord-1.15.3.gemspec:${PORTSDIR}/databases/rubygem-activerecord \
		${LOCALBASE}/${SPEC_DIR}/actionpack-1.13.3.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/actionmailer-1.3.3.gemspec:${PORTSDIR}/mail/rubygem-actionmailer \
		${LOCALBASE}/${SPEC_DIR}/actionwebservice-1.2.3.gemspec:${PORTSDIR}/www/rubygem-actionwebservice
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	FCGI "FastCGI support" Off\
		MEMCACHE_CLIENT "MemCache-Client support" Off
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes

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

.if defined(WITH_FCGI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/fcgi.so:${PORTSDIR}/www/ruby-fcgi
.endif

.if defined(WITH_MEMCACHE_CLIENT)
RUN_DEPENDS+=	${LOCALBASE}/${SPEC_DIR}/memcache-client-1.2.0.gemspec:${PORTSDIR}/databases/rubygem-memcache-client
.endif

.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
