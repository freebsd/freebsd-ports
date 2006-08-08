# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	1.1.2
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jw@innerewut.de
COMMENT=	MVC web application framework

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		${LOCALBASE}/${SPEC_DIR}/activesupport-1.3.1.gemspec:${PORTSDIR}/devel/rubygem-activesupport \
		${LOCALBASE}/${SPEC_DIR}/actionpack-1.12.1.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/actionwebservice-1.1.2.gemspec:${PORTSDIR}/www/rubygem-actionwebservice \
		${LOCALBASE}/${SPEC_DIR}/actionmailer-1.2.1.gemspec:${PORTSDIR}/mail/rubygem-actionmailer \
		${LOCALBASE}/${SPEC_DIR}/activerecord-1.14.2.gemspec:${PORTSDIR}/databases/rubygem-activerecord
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	FCGI "FastCGI support" Off\
		MEMCACHE_CLIENT "MemCache-Client support" Off
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_FCGI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/fcgi.so:${PORTSDIR}/www/ruby-fcgi
.endif

.if defined(WITH_MEMCACHE_CLIENT)
RUN_DEPENDS+=	${LOCALBASE}/${SPEC_DIR}/memcache-client-1.0.3.gemspec:${PORTSDIR}/databases/rubygem-memcache-client
.endif

.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
