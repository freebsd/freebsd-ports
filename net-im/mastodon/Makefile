# $FreeBSD$

PORTNAME=	mastodon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.7
CATEGORIES=	net-im www

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	GNU Social-compatible microblogging server

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg>0:multimedia/ffmpeg \
		libpqtypes>1.5.0:databases/libpqtypes \
		npm>=0:www/npm

# Dependencies below match Gemfile layout
RUN_DEPENDS+=	rubygem-pkg-config>=1.2.0:devel/rubygem-pkg-config

RUN_DEPENDS+=	rubygem-puma>0:www/rubygem-puma \
		rubygem-rails5>0:www/rubygem-rails5 \
		rubygem-uglifier>0:www/rubygem-uglifier

RUN_DEPENDS+=	rubygem-hamlit-rails-rails5>0:www/rubygem-hamlit-rails-rails5 \
		rubygem-pg>0:databases/rubygem-pg \
		rubygem-pghero-rails5>0:databases/rubygem-pghero-rails5 \
		rubygem-dotenv-rails-rails5>0:misc/rubygem-dotenv-rails-rails5

RUN_DEPENDS+=	rubygem-aws-sdk>0:devel/rubygem-aws-sdk \
		rubygem-paperclip-rails5>0:devel/rubygem-paperclip-rails5 \
		rubygem-paperclip-av-transcoder>0:multimedia/rubygem-paperclip-av-transcoder

RUN_DEPENDS+=	rubygem-addressable>0:www/rubygem-addressable \
		rubygem-browser>0:www/rubygem-browser \
		rubygem-cld3>0:textproc/rubygem-cld3 \
		rubygem-devise-rails5>0:devel/rubygem-devise-rails5 \
		rubygem-devise-two-factor-rails5>0:security/rubygem-devise-two-factor-rails5 \
		rubygem-doorkeeper-rails5>0:security/rubygem-doorkeeper-rails5 \
		rubygem-fast_blank>0:devel/rubygem-fast_blank \
		rubygem-goldfinger>0:www/rubygem-goldfinger \
		rubygem-hiredis>0:databases/rubygem-hiredis \
		rubygem-redis-namespace>0:databases/rubygem-redis-namespace \
		rubygem-htmlentities>0:textproc/rubygem-htmlentities \
		rubygem-http>0:www/rubygem-http \
		rubygem-http_accept_language>0:devel/rubygem-http_accept_language \
		rubygem-httplog>0:sysutils/rubygem-httplog \
		rubygem-kaminari-rails5>0:www/rubygem-kaminari-rails5 \
		rubygem-link_header>0:www/rubygem-link_header \
		rubygem-nokogiri>0:textproc/rubygem-nokogiri \
		rubygem-oj>0:devel/rubygem-oj \
		rubygem-ostatus2>0:www/rubygem-ostatus2 \
		rubygem-ox>0:textproc/rubygem-ox \
		rubygem-pundit>0:security/rubygem-pundit \
		rubygem-rabl>0:devel/rubygem-rabl \
		rubygem-rack-attack>0:www/rubygem-rack-attack \
		rubygem-rack-cors>0:www/rubygem-rack-cors \
		rubygem-rack-timeout>0:www/rubygem-rack-timeout \
		rubygem-rails-i18n>0:devel/rubygem-rails-i18n \
		rubygem-rails-settings-cached-rails5>0:www/rubygem-rails-settings-cached-rails5 \
		rubygem-redis>0:databases/rubygem-redis \
		rubygem-rqrcode>0:www/rubygem-rqrcode \
		rubygem-ruby-oembed>0:www/rubygem-ruby-oembed \
		rubygem-sanitize>0:textproc/rubygem-sanitize \
		rubygem-sidekiq>0:devel/rubygem-sidekiq \
		rubygem-sidekiq-scheduler>0:devel/rubygem-sidekiq-scheduler \
		rubygem-sidekiq-unique-jobs>0:devel/rubygem-sidekiq-unique-jobs \
		rubygem-sidekiq-bulk-rails5>0:devel/rubygem-sidekiq-bulk-rails5 \
		rubygem-simple-navigation>0:devel/rubygem-simple-navigation \
		rubygem-simple_form-rails5>0:devel/rubygem-simple_form-rails5 \
		rubygem-sprockets-rails-rails5>0:devel/rubygem-sprockets-rails-rails5 \
		rubygem-statsd-instrument>0:devel/rubygem-statsd-instrument \
		rubygem-twitter-text>0:textproc/rubygem-twitter-text \
		rubygem-tzinfo-data>0:devel/rubygem-tzinfo-data \
		rubygem-webpacker-rails5>0:devel/rubygem-webpacker-rails5

RUN_DEPENDS+=	rubygem-lograge-rails5>0:www/rubygem-lograge-rails5 \
		rubygem-redis-rails-rails5>0:www/rubygem-redis-rails-rails5

USES=		gnome pgsql shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	tootsuite
USE_GNOME=	libxml2 libxslt
USE_RC_SUBR=	mastodon_stream mastodon_web mastodon_workers
USE_RUBY=	yes

SHEBANG_FILES=	bin/*

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST+=	RAKE="${LOCALBASE}/bin/rake" RUBY="${RUBY_NAME}"
SUB_FILES=	900.mastodon nginx.conf nginx-include.conf

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/config/environments/production.rb

do-install:
	${RM} ${WRKSRC}/Gemfile.lock \
		${WRKSRC}/lib/tasks/auto_annotate_models.rake
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/periodic/daily \
		${STAGEDIR}${WWWDIR} ${STAGEDIR}/var/log/mastodon
	${INSTALL_SCRIPT} ${WRKDIR}/900.mastodon \
		${STAGEDIR}${LOCALBASE}/etc/periodic/daily
	${INSTALL_DATA} ${WRKDIR}/nginx.conf \
		${STAGEDIR}${WWWDIR}/nginx.conf.sample
	${INSTALL_DATA} ${WRKDIR}/nginx-include.conf \
		${STAGEDIR}${WWWDIR}/nginx-include.conf.sample
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
