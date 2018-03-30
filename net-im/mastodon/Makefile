# $FreeBSD$

PORTNAME=	mastodon
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.3
CATEGORIES=	net-im www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Social-compatible microblogging server

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yarn>:www/yarn\
		${BR_DEPENDS}
LIB_DEPENDS=	libidn2.so:dns/libidn2
RUN_DEPENDS=	${BR_DEPENDS}

BR_DEPENDS=	libpqtypes>1.5.0:databases/libpqtypes\
		rubygem-pkg-config>=1.2.3:devel/rubygem-pkg-config\
		rubygem-puma>=3.10:www/rubygem-puma\
		rubygem-rails5>=5.1.4:www/rubygem-rails5\
		rubygem-hamlit-rails-rails5>=0.2.0:www/rubygem-hamlit-rails-rails5\
		rubygem-pg>=0.21.0:databases/rubygem-pg\
		rubygem-pghero-rails5>=2.0.0:databases/rubygem-pghero-rails5\
		rubygem-dotenv-rails-rails5>=2.2:misc/rubygem-dotenv-rails-rails5\
		rubygem-aws-sdk>=2.10:devel/rubygem-aws-sdk\
		rubygem-fog-core1>=1.45:devel/rubygem-fog-core1\
		rubygem-fog-local>=0.4:net/rubygem-fog-local\
		rubygem-fog-openstack>=0.1:net/rubygem-fog-openstack\
		rubygem-paperclip-rails5>=5.1.0:devel/rubygem-paperclip-rails5\
		rubygem-paperclip-av-transcoder>=0.6:multimedia/rubygem-paperclip-av-transcoder\
		rubygem-streamio-ffmpeg>=3.0:multimedia/rubygem-streamio-ffmpeg\
		rubygem-active_model_serializers>=0.10:databases/rubygem-active_model_serializers\
		rubygem-addressable>=2.5:www/rubygem-addressable\
		rubygem-bootsnap>=0:devel/rubygem-bootsnap\
		rubygem-browser>=2.4.0:www/rubygem-browser\
		rubygem-charlock_holmes>=0.7.5:textproc/rubygem-charlock_holmes\
		rubygem-iso-639>=0.2.8:textproc/rubygem-iso-639\
		rubygem-chewy>=0.10:textproc/rubygem-chewy\
		rubygem-cld3>=3.2.0:textproc/rubygem-cld3\
		rubygem-devise-rails5>=4.4:devel/rubygem-devise-rails5\
		rubygem-devise-two-factor-rails5>=3.0:security/rubygem-devise-two-factor-rails5\
		rubygem-devise_pam_authenticatable2>=8.0:security/rubygem-devise_pam_authenticatable2\
		rubygem-net-ldap>=0.10:net/rubygem-net-ldap\
		rubygem-omniauth-cas>=1.1:security/rubygem-omniauth-cas\
		rubygem-omniauth-saml>=1.10:security/rubygem-omniauth-saml\
		rubygem-omniauth>=1.2:security/rubygem-omniauth\
		rubygem-doorkeeper-rails5>=4.2:security/rubygem-doorkeeper-rails5\
		rubygem-fast_blank>=1.0:devel/rubygem-fast_blank\
		rubygem-fastimage>=0:graphics/rubygem-fastimage\
		rubygem-goldfinger>=2.1:www/rubygem-goldfinger\
		rubygem-hiredis>=0.6:databases/rubygem-hiredis\
		rubygem-redis-namespace>=1.5:databases/rubygem-redis-namespace\
		rubygem-htmlentities>=4.3:textproc/rubygem-htmlentities\
		rubygem-http>=3.0:www/rubygem-http\
		rubygem-http_accept_language>=2.1:devel/rubygem-http_accept_language\
		rubygem-httplog>=0.99:sysutils/rubygem-httplog\
		rubygem-idn-ruby>=0.1.0:dns/rubygem-idn-ruby\
		rubygem-kaminari-rails5>=1.1:www/rubygem-kaminari-rails5\
		rubygem-link_header>=0.0.8:www/rubygem-link_header\
		rubygem-mime-types>=3.1:misc/rubygem-mime-types\
		rubygem-nokogiri>=1.8:textproc/rubygem-nokogiri\
		rubygem-nsa-rails5>=0.2:devel/rubygem-nsa-rails5\
		rubygem-oj>=3.3:devel/rubygem-oj\
		rubygem-ostatus2>=2.0:www/rubygem-ostatus2\
		rubygem-ox>=2.8:textproc/rubygem-ox\
		rubygem-pundit>=1.1:security/rubygem-pundit\
		rubygem-premailer-rails-rails5>=0:mail/rubygem-premailer-rails-rails5\
		rubygem-rack-attack>=5.0:www/rubygem-rack-attack\
		rubygem-rack-cors0>=0.4:www/rubygem-rack-cors0\
		rubygem-rack-timeout>=0.4:www/rubygem-rack-timeout\
		rubygem-rails-i18n>=5.0:devel/rubygem-rails-i18n\
		rubygem-rails-settings-cached-rails5>=0.6:www/rubygem-rails-settings-cached-rails5\
		rubygem-redis>=4.0:databases/rubygem-redis\
		rubygem-mario-redis-lock>=1.2:databases/rubygem-mario-redis-lock\
		rubygem-rqrcode>=0.10:www/rubygem-rqrcode\
		rubygem-ruby-oembed>=0.12:www/rubygem-ruby-oembed\
		rubygem-ruby-progressbar>=1.4:devel/rubygem-ruby-progressbar\
		rubygem-sanitize>=4.4:textproc/rubygem-sanitize\
		rubygem-sidekiq>=5.0:devel/rubygem-sidekiq\
		rubygem-sidekiq-scheduler>=2.1:devel/rubygem-sidekiq-scheduler\
		rubygem-sidekiq-unique-jobs>=5.0:devel/rubygem-sidekiq-unique-jobs\
		rubygem-sidekiq-bulk-rails5>=0.1.1:devel/rubygem-sidekiq-bulk-rails5\
		rubygem-simple-navigation>=4.0:devel/rubygem-simple-navigation\
		rubygem-simple_form-rails5>=3.4:devel/rubygem-simple_form-rails5\
		rubygem-sprockets-rails-rails5>=3.2:devel/rubygem-sprockets-rails-rails5\
		rubygem-strong_migrations>=0.1.9:devel/rubygem-strong_migrations\
		rubygem-tty-command>=0:devel/rubygem-tty-command\
		rubygem-tty-prompt>=0:devel/rubygem-tty-prompt\
		rubygem-twitter-text1>=1.14:textproc/rubygem-twitter-text1\
		rubygem-tzinfo-data>=1.2017:devel/rubygem-tzinfo-data\
		rubygem-webpacker-rails5>=3.0:devel/rubygem-webpacker-rails5\
		rubygem-webpush>=0.3.2_1:security/rubygem-webpush\
		rubygem-json-ld-preloaded>=2.2.1:converters/rubygem-json-ld-preloaded\
		rubygem-rdf-normalize>=0.3.1:www/rubygem-rdf-normalize\
		rubygem-private_address_check>=0.4.1:net/rubygem-private_address_check\
		rubygem-lograge-rails5>=0.7:www/rubygem-lograge-rails5\
		rubygem-redis-rails-rails5>=5.0.2:www/rubygem-redis-rails-rails5

USES=		gmake gnome pgsql python:2.7,build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	tootsuite jehops:mn
GH_PROJECT=	mastodon_node:mn
GH_TAGNAME=	2.3.2:mn
USE_GNOME=	libxml2 libxslt
USE_RC_SUBR=	mastodon_stream mastodon_web mastodon_workers
USE_RUBY=	yes

NODE_BIN=	${LOCALBASE}/bin/node
NODE_ABI=	${NODE_VER:C/v4.*/46/:C/v6.*/48/:C/v8.*/57/:C/v9.*/59/}
PLIST_SUB=	NODE_ABI=${NODE_ABI}\
		RUBY_SUFFIX=
SHEBANG_FILES=	bin/*
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
SUB_LIST+=	RAKE="${LOCALBASE}/bin/rake" RUBY="${RUBY_NAME}"
SUB_FILES=	nginx.conf nginx-include.conf
X=		00000000000000000000000000000000
XX=		0000000000000000000000000000000000000000000000000000000000000000

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'\
		${WRKSRC}/config/environments/production.rb

do-build:
	@${RM} ${WRKSRC}/Gemfile.lock
	HOME=${WRKSRC_mn} yarn config set yarn-offline-mirror ${WRKSRC_mn} --offline
	HOME=${WRKSRC_mn} yarn config set nodedir ${LOCALBASE} --offline
	HOME=${WRKSRC_mn} yarn config set python ${PYTHON_CMD} --offline
	@${CP} ${FILESDIR}/yarn.lock.in ${WRKSRC}/yarn.lock
	(cd ${WRKSRC};\
		HOME=${WRKSRC_mn} yarn --offline;\
		OTP_SECRET=x SECRET_KEY_BASE=x RAILS_ENV=production rails --trace webpacker:binstubs;\
		HOME=${WRKSRC_mn} OTP_SECRET=x SECRET_KEY_BASE=x RAILS_ENV=production rails --trace assets:precompile)
	(cd ${WRKSRC}/public/assets &&\
		${MV} .sprockets-manifest-*.json .sprockets-manifest-${X}.json &&\
		${MV} doorkeeper/application-*.css doorkeeper/application-${XX}.css &&\
		${MV} doorkeeper/application-*.css.gz doorkeeper/application-${XX}.css.gz &&\
		${MV} doorkeeper/admin/application-*.css doorkeeper/admin/application-${XX}.css &&\
		${MV} doorkeeper/admin/application-*.css.gz doorkeeper/admin/application-${XX}.css.gz &&\
		${MV} pghero/application-*.css pghero/application-${XX}.css &&\
		${MV} pghero/application-*.css.gz pghero/application-${XX}.css.gz &&\
		${MV} pghero/application-*.js pghero/application-${XX}.js &&\
		${MV} pghero/application-*.js.gz pghero/application-${XX}.js.gz &&\
		${MV} pghero/favicon-*.png pghero/favicon-${XX}.png)
	@${REINPLACE_CMD} -e 's|application-[0-9A-Za-z]\{64\}|application-${XX}|g'\
		${WRKSRC}/public/assets/.sprockets-manifest-${X}.json
	@${REINPLACE_CMD} -e 's|"digest":"[0-9A-Za-z]\{64\}"|"digest":"${XX}"|g'\
		${WRKSRC}/public/assets/.sprockets-manifest-${X}.json
	@${REINPLACE_CMD} -e\
		"s|^  cache_dir:.*|  cache_dir: '/var/cache/mastodon',|"\
		${WRKSRC}/config/boot.rb
do-install:
	@${RM} -r ${WRKSRC}/node_modules/emoji*\
		${WRKSRC}/node_modules/*/man\
		${WRKSRC}/node_modules/*/node_modules\
		${WRKSRC}/node_modules/node-sass\
		${WRKSRC}/node_modules/uws/build\
		${WRKSRC}/node_modules/babel-preset-env/.github\
		${WRKSRC}/node_modules/redis/.github
	@${RM}	${WRKSRC}/Gemfile.lock\
		${WRKSRC}/lib/tasks/auto_annotate_models.rake\
		${WRKSRC}/node_modules/uws/uws_darwin_*\
		${WRKSRC}/node_modules/uws/uws_linux_*\
		${WRKSRC}/node_modules/uws/uws_win32_*\
		${WRKSRC}/node_modules/stringz/coverage/lcov.info\
		${WRKSRC}/node_modules/.bin/node-sass\
		${WRKSRC}/node_modules/uws/build_log.txt
	${STRIP_CMD} ${WRKSRC}/node_modules/uws/uws_freebsd_${NODE_ABI}.node
	@${MKDIR} ${STAGEDIR}/var/cache/${PORTNAME} \
		${STAGEDIR}/var/log/${PORTNAME}\
		${STAGEDIR}/var/run/${PORTNAME}\
		${STAGEDIR}${WWWDIR}/public/system
	${INSTALL_DATA} ${WRKDIR}/nginx.conf\
		${STAGEDIR}${WWWDIR}/nginx.conf.sample
	${INSTALL_DATA} ${WRKDIR}/nginx-include.conf\
		${STAGEDIR}${WWWDIR}/nginx-include.conf.sample
	${INSTALL_DATA} ${WRKSRC}/.env.production.sample ${WRKSRC}/app.json\
			${WRKSRC}/config.ru ${WRKSRC}/Gemfile ${WRKSRC}/LICENSE\
			${WRKSRC}/package.json ${WRKSRC}/Rakefile\
		${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE}\
		"app bin config db lib log node_modules public spec streaming vendor"\
		${STAGEDIR}${WWWDIR})
	:>${STAGEDIR}${WWWDIR}/Gemfile.lock

.include <bsd.port.pre.mk>

.if exists(${NODE_BIN})
NODE_VER!=	${NODE_BIN} -v
.endif

.include <bsd.port.post.mk>
