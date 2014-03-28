# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	3.2.17
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MVC web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionmailer>=${PORTVERSION}:${PORTSDIR}/mail/rubygem-actionmailer \
		rubygem-actionpack>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-activerecord>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-activeresource>=${PORTVERSION}:${PORTSDIR}/www/rubygem-activeresource \
		rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-bundler>=1.0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-railties>=${PORTVERSION}:${PORTSDIR}/www/rubygem-railties \
		rubygem-builder>=3.0.4:${PORTSDIR}/devel/rubygem-builder \
		rubygem-coffee-rails>=3.2.2:${PORTSDIR}/devel/rubygem-coffee-rails \
		rubygem-i18n>=0.6.1:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-jquery-rails>=3.1.0:${PORTSDIR}/www/rubygem-jquery-rails \
		rubygem-json>=1.7.6:${PORTSDIR}/devel/rubygem-json \
		rubygem-rack>=1.4.4:${PORTSDIR}/www/rubygem-rack \
		rubygem-rack-test>=0.6.1:${PORTSDIR}/www/rubygem-rack-test \
		rubygem-rake>=10.1.1:${PORTSDIR}/devel/rubygem-rake \
		rubygem-sass-rails>=3.2.6:${PORTSDIR}/textproc/rubygem-sass-rails \
		rubygem-sqlite3>=1.3.9:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-treetop>=1.4.15:${PORTSDIR}/devel/rubygem-treetop \
		rubygem-turn>=0.8.3:${PORTSDIR}/devel/rubygem-turn \
		rubygem-tzinfo>=0.3.39:${PORTSDIR}/devel/rubygem-tzinfo \
		rubygem-uglifier>=2.5.0:${PORTSDIR}/www/rubygem-uglifier \
		node:${PORTSDIR}/www/node

# XXX: rails3 gem no longer has a lib/ dir
# XXX: which breaks devel/ruby-gems specification.
# XXX: and thus rdoc
NOPORTDOCS=	yes

USE_RUBY=	yes
USE_RUBY_RDOC=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS_DEFINE=	FCGI PASSENGER MEMCACHE_CLIENT
FCGI_DESC=	FastCGI backend
MONGRELCLUSTER_DESC=	Mongrel Cluster backend
PASSENGER_DESC=	Passenger backend
MEMCACHE_CLIENT_DESC=	MemCache-Client support
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

FCGI_RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/fcgi.so:${PORTSDIR}/www/ruby-fcgi
MEMCACHE_CLIENT_RUN_DEPENDS=	rubygem-memcache-client>=1.2.0:${PORTSDIR}/databases/rubygem-memcache-client
PASSENGER_RUN_DEPENDS=	rubygem-passenger>=2.2.15:${PORTSDIR}/www/rubygem-passenger

.include <bsd.port.mk>
