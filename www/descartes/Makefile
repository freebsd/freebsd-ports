# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	descartes
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Sinatra-based dashboard for graphite

RUN_DEPENDS=	rubygem-rake>=0:${PORTSDIR}/devel/rubygem-rake \
	rubygem-sinatra>=0:${PORTSDIR}/www/rubygem-sinatra \
	rubygem-thin>=0:${PORTSDIR}/www/rubygem-thin \
	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg \
	rubygem-sequel>=0:${PORTSDIR}/devel/rubygem-sequel \
	rubygem-omniauth>=0:${PORTSDIR}/www/rubygem-omniauth \
	rubygem-omniauth-google-apps>=0:${PORTSDIR}/www/rubygem-omniauth-google-apps \
	rubygem-sinatra_auth_github>=0:${PORTSDIR}/www/rubygem-sinatra_auth_github \
	rubygem-openid-redis-store>=0:${PORTSDIR}/www/rubygem-openid-redis-store \
	rubygem-rack-canonical-host>=0:${PORTSDIR}/www/rubygem-rack-canonical-host \
	rubygem-rack-ssl-enforcer>=0:${PORTSDIR}/www/rubygem-rack-ssl-enforcer \
	rubygem-rest-client>=0:${PORTSDIR}/www/rubygem-rest-client \
	rubygem-haml>=0:${PORTSDIR}/www/rubygem-haml \
	rubygem-json>=0:${PORTSDIR}/devel/rubygem-json \
	rubygem-rspec>=0:${PORTSDIR}/devel/rubygem-rspec \
	rubygem-rufus-scheduler>=0:${PORTSDIR}/devel/rubygem-rufus-scheduler \
	rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri \
	rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
	rubygem-foreman>=0:${PORTSDIR}/www/rubygem-foreman \
	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss

USE_RUBY=	yes
USE_GITHUB=	yes
# XXX the upstream has not yet released, or tagged, the source. tag PORTVERSION
# in our own fork
GH_ACCOUNT=	reallyenglish
GH_PROJECT=	descartes
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	65093f7

NO_BUILD=	yes

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR})

# TODO
# - rc.subr
.include <bsd.port.mk>
