# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	1.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	http://rubyforge.org/frs/download.php/7653/

MAINTAINER=	jw@innerewut.de
COMMENT=	MVC web application framework

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		${LOCALBASE}/${SPEC_DIR}/activesupport-1.2.5.gemspec:${PORTSDIR}/devel/rubygem-activesupport \
		${LOCALBASE}/${SPEC_DIR}/actionpack-1.11.2.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/actionwebservice-1.0.0.gemspec:${PORTSDIR}/www/rubygem-actionwebservice \
		${LOCALBASE}/${SPEC_DIR}/actionmailer-1.1.5.gemspec:${PORTSDIR}/mail/rubygem-actionmailer \
		${LOCALBASE}/${SPEC_DIR}/activerecord-1.13.2.gemspec:${PORTSDIR}/databases/rubygem-activerecord
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
