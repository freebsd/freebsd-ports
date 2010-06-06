# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	2.3.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MVC web application framework

RUN_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-${PORTVERSION}.gemspec:${PORTSDIR}/devel/rubygem-activesupport \
		${LOCALBASE}/${SPEC_DIR}/activerecord-${PORTVERSION}.gemspec:${PORTSDIR}/databases/rubygem-activerecord \
		${LOCALBASE}/${SPEC_DIR}/actionpack-${PORTVERSION}.gemspec:${PORTSDIR}/www/rubygem-actionpack \
		${LOCALBASE}/${SPEC_DIR}/actionmailer-${PORTVERSION}.gemspec:${PORTSDIR}/mail/rubygem-actionmailer \
		${LOCALBASE}/${SPEC_DIR}/activeresource-${PORTVERSION}.gemspec:${PORTSDIR}/www/rubygem-activeresource

OPTIONS=	FCGI "FastCGI support" Off\
		MEMCACHE_CLIENT "MemCache-Client support" Off
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rails

.include <bsd.port.pre.mk>

.if defined(WITH_FCGI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/fcgi.so:${PORTSDIR}/www/ruby-fcgi
.endif

.if defined(WITH_MEMCACHE_CLIENT)
RUN_DEPENDS+=	rubygem-memcache-client>=1.2.0:${PORTSDIR}/databases/rubygem-memcache-client
.endif

.include <bsd.port.post.mk>
