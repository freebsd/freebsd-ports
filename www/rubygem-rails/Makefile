# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	3.0.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MVC web application framework

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activerecord>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-actionpack>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-actionmailer>=${PORTVERSION}:${PORTSDIR}/mail/rubygem-actionmailer \
		rubygem-activeresource>=${PORTVERSION}:${PORTSDIR}/www/rubygem-activeresource \
		rubygem-railties>=${PORTVERSION}:${PORTSDIR}/www/rubygem-railties \
		rubygem-bundler>=1.0:${PORTSDIR}/sysutils/rubygem-bundler

# XXX: rails3 gem no longer has a lib/ dir
# XXX: which breaks devel/ruby-gems specification.
# XXX: and thus rdoc
NOPORTDOCS=yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes
PLIST_FILES=	bin/rails

OPTIONS= \
	FCGI 			"FastCGI backend" 			Off \
	MONGREL			"Mongrel backend"			Off \
	MONGRELCLUSTER	"Mongrel Cluster backend"	Off \
	PASSENGER		"Passenger backend"			Off \
	MEMCACHE_CLIENT "MemCache-Client support" 	Off
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

.include <bsd.port.options.mk>

.if defined(WITH_FCGI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/fcgi.so:${PORTSDIR}/www/ruby-fcgi
.endif

.if defined(WITH_MEMCACHE_CLIENT)
RUN_DEPENDS+=	rubygem-memcache-client>=1.2.0:${PORTSDIR}/databases/rubygem-memcache-client
.endif

.if defined(WITH_MONGREL)
RUN_DEPENDS+=	rubygem-mongrel>=1.1.5:${PORTSDIR}/www/rubygem-mongrel
.endif

.if defined(WITH_MONGRELCLUSTER)
RUN_DEPENDS+=	rubygem-mongrel_cluster>=1.0.5:${PORTSDIR}/www/rubygem-mongrel_cluster
.endif

.if defined(WITH_PASSENGER)
RUN_DEPENDS+=	rubygem-passenger>=2.2.15:${PORTSDIR}/www/rubygem-passenger
.endif

.include <bsd.port.mk>
