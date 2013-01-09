# Ports collection makefile for:	rubygem-rails
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	3.2.11
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
		rubygem-rake>=10.0.3:${PORTSDIR}/devel/rubygem-rake \
		rubygem-sass-rails>=3.2.5:${PORTSDIR}/textproc/rubygem-sass-rails \
		rubygem-coffee-rails>=3.2.2:${PORTSDIR}/devel/rubygem-coffee-rails \
		rubygem-jquery-rails>=2.1.4:${PORTSDIR}/www/rubygem-jquery-rails \
		rubygem-sqlite3>=1.3.6:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-uglifier>=1.3.0:${PORTSDIR}/www/rubygem-uglifier \
		rubygem-bundler>=1.1.5:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-treetop>=1.4.12:${PORTSDIR}/devel/rubygem-treetop \
		rubygem-json>=1.7.6:${PORTSDIR}/devel/rubygem-json \
		rubygem-tzinfo>=0.3.35:${PORTSDIR}/devel/rubygem-tzinfo \
		rubygem-builder>=3.0.4:${PORTSDIR}/devel/rubygem-builder \
		rubygem-i18n>=0.6.1:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-rack>=1.4.3:${PORTSDIR}/www/rubygem-rack \
		rubygem-rack-test>=0.6.1:${PORTSDIR}/www/rubygem-rack-test \
		node:${PORTSDIR}/www/node

# XXX: rails3 gem no longer has a lib/ dir
# XXX: which breaks devel/ruby-gems specification.
# XXX: and thus rdoc
NOPORTDOCS=yes

USE_RUBY=	yes
USE_RUBY_RDOC=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes

OPTIONS= \
	FCGI 			"FastCGI backend" 			Off \
	MONGREL			"Mongrel backend"			Off \
	MONGRELCLUSTER		"Mongrel Cluster backend"		Off \
	PASSENGER		"Passenger backend"			Off \
	MEMCACHE_CLIENT		"MemCache-Client support" 		Off
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

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
RUN_DEPENDS+=	rubygem-turn>=0.8.3:${PORTSDIR}/devel/rubygem-turn
.endif

.include <bsd.port.post.mk>
