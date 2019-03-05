# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-ce
PORTVERSION=	11.8.1
CATEGORIES=	www devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Web GUI for managing git repositories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# the rubygems of RUN_DEPENDS matches the order of the Gemfile
# which makes maintaining this long list much easier!
# only rubygem-pg and rubygem-mysql are defined later as RUN_DEPENDS
# for the options
MY_DEPENDS=	git>=2.16.2:devel/git \
	gitlab-shell>=8.4.4:devel/gitlab-shell \
	gitlab-workhorse>=8.3.1:www/gitlab-workhorse \
	gitaly>=1.20.0:devel/gitaly \
	gitlab-pages>=1.5.0:www/gitlab-pages \
	redis>=3.2.12:databases/redis \
	yarn>=1.10.0:www/yarn \
	rubygem-rails50>=5.0.7.1:www/rubygem-rails50 \
	rubygem-rails-deprecated_sanitizer-rails50>=1.0.3:devel/rubygem-rails-deprecated_sanitizer-rails50 \
	rubygem-nakayoshi_fork>=0.0.4:devel/rubygem-nakayoshi_fork \
	rubygem-responders-rails50>=2.0:www/rubygem-responders-rails50 \
	rubygem-sprockets3>=3.7:devel/rubygem-sprockets3 \
	rubygem-gitlab-default_value_for>=3.1.1:devel/rubygem-gitlab-default_value_for \
	rubygem-rugged>=0.27.0:devel/rubygem-rugged \
	rubygem-grape-path-helpers>=1.0:devel/rubygem-grape-path-helpers \
	rubygem-faraday>=0.12.0:www/rubygem-faraday \
	rubygem-devise-rails50>=4.4:devel/rubygem-devise-rails50 \
	rubygem-doorkeeper43>=4.3:security/rubygem-doorkeeper43 \
	rubygem-doorkeeper-openid_connect>=1.5:security/rubygem-doorkeeper-openid_connect \
	rubygem-omniauth>=1.8:security/rubygem-omniauth \
	rubygem-omniauth-auth0>=2.0.0:net/rubygem-omniauth-auth0 \
	rubygem-omniauth-azure-oauth2>=0.0.9:net/rubygem-omniauth-azure-oauth2 \
	rubygem-omniauth-cas3>=1.1.4:security/rubygem-omniauth-cas3 \
	rubygem-omniauth-facebook4>=4.0.0:net/rubygem-omniauth-facebook4 \
	rubygem-omniauth-github>=1.3.0:net/rubygem-omniauth-github \
	rubygem-omniauth-gitlab>=1.0.2:security/rubygem-omniauth-gitlab \
	rubygem-omniauth-google-oauth2>=0.6.0:net/rubygem-omniauth-google-oauth2 \
	rubygem-omniauth-kerberos>=0.3.0:net/rubygem-omniauth-kerberos \
	rubygem-omniauth-oauth2-generic>=0.2.2:security/rubygem-omniauth-oauth2-generic \
	rubygem-omniauth-saml>=1.10:security/rubygem-omniauth-saml \
	rubygem-omniauth-shibboleth>=1.3.0:security/rubygem-omniauth-shibboleth \
	rubygem-omniauth-twitter>=1.4:net/rubygem-omniauth-twitter \
	rubygem-omniauth_crowd22>=2.2.0:devel/rubygem-omniauth_crowd22 \
	rubygem-omniauth-authentiq>=0.3.3:net/rubygem-omniauth-authentiq \
	rubygem-rack-oauth212>=1.2.1:security/rubygem-rack-oauth212 \
	rubygem-jwt>=2.1.0:www/rubygem-jwt \
	rubygem-recaptcha3>=3.0:devel/rubygem-recaptcha3 \
	rubygem-akismet>=2.0:devel/rubygem-akismet \
	rubygem-devise-two-factor-rails50>=3.0.0:security/rubygem-devise-two-factor-rails50 \
	rubygem-rqrcode-rails3>=0.1.7:www/rubygem-rqrcode-rails3 \
	rubygem-attr_encrypted>=3.1.0:security/rubygem-attr_encrypted \
	rubygem-u2f0>=0.2.1:net/rubygem-u2f0 \
	rubygem-validates_hostname>=1.0.6:dns/rubygem-validates_hostname \
	rubygem-rubyzip>=1.2.2:archivers/rubygem-rubyzip \
	rubygem-browser>=2.5:www/rubygem-browser \
	rubygem-gpgme>=2.0.18:security/rubygem-gpgme \
	rubygem-gitlab_omniauth-ldap20>=2.0.4:net/rubygem-gitlab_omniauth-ldap20 \
	rubygem-net-ldap>=0.16.0:net/rubygem-net-ldap \
	rubygem-grape11>=1.1:devel/rubygem-grape11 \
	rubygem-grape-entity>=0.7.1:devel/rubygem-grape-entity \
	rubygem-rack-cors>=1.0.0:www/rubygem-rack-cors \
	rubygem-graphql>=1.8.0:devel/rubygem-graphql \
	rubygem-graphiql-rails>=1.4.10:devel/rubygem-graphiql-rails \
	rubygem-hashie-forbidden_attributes>=0:devel/rubygem-hashie-forbidden_attributes \
	rubygem-kaminari-rails50>=1.0:www/rubygem-kaminari-rails50 \
	rubygem-hamlit>=2.8.8:www/rubygem-hamlit \
	rubygem-carrierwave>=1.3.0:www/rubygem-carrierwave \
	rubygem-mini_magick>=0:graphics/rubygem-mini_magick \
	rubygem-fog-aws2>=2.0.1:net/rubygem-fog-aws2 \
	rubygem-fog-core1>=1.44:devel/rubygem-fog-core1 \
	rubygem-fog-google>=1.7.1:net/rubygem-fog-google \
	rubygem-fog-local>=0.3:net/rubygem-fog-local \
	rubygem-fog-openstack02>=0.1:net/rubygem-fog-openstack02 \
	rubygem-fog-rackspace>=0.1.1:net/rubygem-fog-rackspace \
	rubygem-fog-aliyun02>=0.2.0:net/rubygem-fog-aliyun02 \
	rubygem-google-api-client>=0.23:devel/rubygem-google-api-client \
	rubygem-unf>=0.1.4:textproc/rubygem-unf \
	rubygem-seed-fu>=2.3.7:databases/rubygem-seed-fu \
	rubygem-html-pipeline>=2.8:textproc/rubygem-html-pipeline \
	rubygem-deckar01-task_list>=2.2.0:www/rubygem-deckar01-task_list \
	rubygem-gitlab-markup>=1.6.5:textproc/rubygem-gitlab-markup \
	rubygem-github-markup17>=1.7.0:textproc/rubygem-github-markup17 \
	rubygem-commonmarker>=0.17:textproc/rubygem-commonmarker \
	rubygem-redcloth>=4.3.2:www/rubygem-redcloth \
	rubygem-rdoc>=6.0:devel/rubygem-rdoc \
	rubygem-org-ruby>=0.9.12:textproc/rubygem-org-ruby \
	rubygem-creole>=0.5.0:textproc/rubygem-creole \
	rubygem-wikicloth081>=0.8.1:textproc/rubygem-wikicloth081 \
	rubygem-asciidoctor>=1.5.8:textproc/rubygem-asciidoctor \
	rubygem-asciidoctor-plantuml>=0.0.8:textproc/rubygem-asciidoctor-plantuml \
	rubygem-rouge>=3.1:textproc/rubygem-rouge \
	rubygem-truncato>=0.7.11:textproc/rubygem-truncato \
	rubygem-bootstrap_form>=2.7.0:devel/rubygem-bootstrap_form \
	rubygem-nokogiri>=1.10.1:textproc/rubygem-nokogiri \
	rubygem-escape_utils>=1.1:textproc/rubygem-escape_utils \
	rubygem-icalendar>=0:devel/rubygem-icalendar \
	rubygem-diffy31>=3.1.0:textproc/rubygem-diffy31 \
	rubygem-rack>=2.0.6:www/rubygem-rack \
	rubygem-unicorn51>=5.1.0:www/rubygem-unicorn51 \
	rubygem-unicorn-worker-killer044>=0.4.4:www/rubygem-unicorn-worker-killer044 \
	rubygem-puma>=3.12:www/rubygem-puma \
	rubygem-puma_worker_killer>=0:www/rubygem-puma_worker_killer \
	rubygem-state_machines-activerecord>=0.5.1:databases/rubygem-state_machines-activerecord \
	rubygem-acts-as-taggable-on>=5.0:www/rubygem-acts-as-taggable-on \
	rubygem-sidekiq>=5.2.1:devel/rubygem-sidekiq \
	rubygem-sidekiq-cron>=1.0.0:devel/rubygem-sidekiq-cron \
	rubygem-redis-namespace>=1.6.0:databases/rubygem-redis-namespace \
	rubygem-gitlab-sidekiq-fetcher>=0.4.0:devel/rubygem-gitlab-sidekiq-fetcher \
	rubygem-fugit>=1.1:devel/rubygem-fugit \
	rubygem-httparty>=0.13.3:www/rubygem-httparty \
	rubygem-rainbow>=3.0:devel/rubygem-rainbow \
	rubygem-ruby-progressbar>=0:devel/rubygem-ruby-progressbar \
	rubygem-settingslogic>=2.0.9:devel/rubygem-settingslogic \
	rubygem-re2>=1.1.1:devel/rubygem-re2 \
	rubygem-version_sorter21>=2.1.0:textproc/rubygem-version_sorter21 \
	rubygem-js_regex>=3.1.0:textproc/rubygem-js_regex \
	rubygem-device_detector>=0:devel/rubygem-device_detector \
	rubygem-redis-rails-rails50>=5.0.1:www/rubygem-redis-rails-rails50 \
	rubygem-redis3>=3.2:databases/rubygem-redis3 \
	rubygem-connection_pool>=2.0:net/rubygem-connection_pool \
	rubygem-discordrb-webhooks-blackst0ne>=3.3.0:net-im/rubygem-discordrb-webhooks-blackst0ne \
	rubygem-hipchat15>=1.5.0:net-im/rubygem-hipchat15 \
	rubygem-jira-ruby>=1.4:devel/rubygem-jira-ruby \
	rubygem-flowdock>=0.7:www/rubygem-flowdock \
	rubygem-slack-notifier1>=1.5.1:devel/rubygem-slack-notifier1 \
	rubygem-hangouts-chat>=0.0.5:net/rubygem-hangouts-chat \
	rubygem-asana>=0.8.1:www/rubygem-asana \
	rubygem-ruby-fogbugz021>=0.2.1:devel/rubygem-ruby-fogbugz021 \
	rubygem-kubeclient>=4.2.2:www/rubygem-kubeclient \
	rubygem-sanitize>=4.6:textproc/rubygem-sanitize \
	rubygem-babosa>=1.0.2:textproc/rubygem-babosa \
	rubygem-loofah>=2.2:textproc/rubygem-loofah \
	rubygem-licensee8>=8.9:devel/rubygem-licensee8 \
	rubygem-rack-attack44>=4.4.1:www/rubygem-rack-attack44 \
	rubygem-ace-rails-ap>=4.1.0:www/rubygem-ace-rails-ap \
	rubygem-charlock_holmes>=0.7.5:textproc/rubygem-charlock_holmes \
	rubygem-mimemagic>=0.3.2:misc/rubygem-mimemagic \
	rubygem-fast_blank>=0:devel/rubygem-fast_blank \
	rubygem-chronic>=0.10.2:devel/rubygem-chronic \
	rubygem-chronic_duration>=0.10.6:devel/rubygem-chronic_duration \
	rubygem-webpack-rails-rails50>=0.9.10:www/rubygem-webpack-rails-rails50 \
	rubygem-rack-proxy>=0.6.0:www/rubygem-rack-proxy \
	rubygem-sass-rails-rails50>=5.0.6:textproc/rubygem-sass-rails-rails50 \
	rubygem-sass>=3.5.0:textproc/rubygem-sass \
	rubygem-uglifier27>=2.7.2:www/rubygem-uglifier27 \
	rubygem-addressable>=2.5.2:www/rubygem-addressable \
	rubygem-font-awesome-rails-rails50>=4.7:devel/rubygem-font-awesome-rails-rails50 \
	rubygem-gemojione>=3.3:graphics/rubygem-gemojione \
	rubygem-gon-rails50>=6.2.0:www/rubygem-gon-rails50 \
	rubygem-jquery-atwho-rails13>=1.3.2:www/rubygem-jquery-atwho-rails13 \
	rubygem-request_store>=1.3:devel/rubygem-request_store \
	rubygem-select2-rails3>=3.5.9:www/rubygem-select2-rails3 \
	rubygem-virtus>=1.0.1:devel/rubygem-virtus \
	rubygem-base32>=0.3.0:converters/rubygem-base32 \
	rubygem-sentry-raven>=2.7:devel/rubygem-sentry-raven \
	rubygem-premailer-rails19-rails50>=1.9.7:mail/rubygem-premailer-rails19-rails50 \
	rubygem-ruby_parser>=3.8.4:devel/rubygem-ruby_parser \
	rubygem-rails-i18n-rails50>=5.1.0:devel/rubygem-rails-i18n-rails50 \
	rubygem-gettext_i18n_rails>=1.8.0:devel/rubygem-gettext_i18n_rails \
	rubygem-gettext_i18n_rails_js-rails50>=1.3:devel/rubygem-gettext_i18n_rails_js-rails50 \
	rubygem-gettext>=3.2.2:devel/rubygem-gettext \
	rubygem-batch-loader12>=1.2.2:devel/rubygem-batch-loader12 \
	rubygem-peek-rails50>=1.0.1:devel/rubygem-peek-rails50 \
	rubygem-peek-gc-rails50>=0.0.2:devel/rubygem-peek-gc-rails50 \
	rubygem-peek-rblineprof-rails50>=0.2.0:devel/rubygem-peek-rblineprof-rails50 \
	rubygem-peek-redis-rails50>=1.2.0:devel/rubygem-peek-redis-rails50 \
	rubygem-prometheus-client-mmap>=0.9.4:devel/rubygem-prometheus-client-mmap \
	rubygem-opentracing04>=0.4.3:devel/rubygem-opentracing04 \
	rubygem-jaeger-client>=0.10.0:devel/rubygem-jaeger-client \
	rubygem-octokit>=4.9:net/rubygem-octokit \
	rubygem-mail_room>=0.9.1:mail/rubygem-mail_room \
	rubygem-email_reply_trimmer>=0.1:mail/rubygem-email_reply_trimmer \
	rubygem-html2text>=0:textproc/rubygem-html2text \
	rubygem-ruby-prof>=0.17.0:devel/rubygem-ruby-prof \
	rubygem-rbtrace>=0.4:devel/rubygem-rbtrace \
	rubygem-oauth2>=1.4.0:net/rubygem-oauth2 \
	rubygem-health_check26-rails50>=2.6.0:devel/rubygem-health_check26-rails50 \
	rubygem-vmstat>=2.3.0:sysutils/rubygem-vmstat \
	rubygem-sys-filesystem>=1.1.6:sysutils/rubygem-sys-filesystem \
	rubygem-net-ssh>=5.0:security/rubygem-net-ssh \
	rubygem-sshkey1>=1.9.0:security/rubygem-sshkey1 \
	rubygem-ed25519>=1.2:security/rubygem-ed25519 \
	rubygem-bcrypt_pbkdf>=1.0:security/rubygem-bcrypt_pbkdf \
	rubygem-gitaly-proto>=1.10.0:net/rubygem-gitaly-proto \
	rubygem-grpc>=1.15.0:net/rubygem-grpc \
	rubygem-gitaly>=0.8.0:net/rubygem-gitaly \
	rubygem-google-protobuf>=3.6:devel/rubygem-google-protobuf \
	rubygem-toml-rb10>=1.0.0:www/rubygem-toml-rb10 \
	rubygem-flipper013>=0.13.0:devel/rubygem-flipper013 \
	rubygem-flipper-active_record013>=0.13.0:databases/rubygem-flipper-active_record013 \
	rubygem-flipper-active_support_cache_store013>=0.13.0:devel/rubygem-flipper-active_support_cache_store013 \
	rubygem-lograge-rails50>=0.5:www/rubygem-lograge-rails50 \
	rubygem-grape_logging>=1.7:devel/rubygem-grape_logging

BUILD_DEPENDS=	gem:devel/ruby-gems \
	${MY_DEPENDS}

RUN_DEPENDS=	${MY_DEPENDS}

OPTIONS_SINGLE=	DATABASE
OPTIONS_SINGLE_DATABASE=	PGSQL MYSQL
OPTIONS_DEFAULT=	PGSQL
PGSQL_DESC=	Default PostgreSQL support (preferred)
MYSQL_DESC=	Optional MySQL support

PGSQL_RUN_DEPENDS=	rubygem-pg>=1.1.0:databases/rubygem-pg \
	rubygem-peek-pg-rails50>=1.3.0:databases/rubygem-peek-pg-rails50
MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0.4.5:databases/rubygem-mysql2 \
	rubygem-peek-mysql2-rails50>=1.2.0:databases/rubygem-peek-mysql2-rails50

USE_RUBY=	yes

USE_RC_SUBR=	gitlab
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the here: https://gitlab.com/gitlab-org/gitlab-ce/tags
GL_COMMIT=	657d5085256165ceaeb443891f8e14eeba82aaba

USERS=	git
GROUPS=	git

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config/gitlab.yml.example \
		${WRKSRC}/config/unicorn.rb.example \
		${WRKSRC}/lib/support/nginx/gitlab \
		${WRKSRC}/lib/support/nginx/gitlab-ssl

post-patch-MYSQL-on:
	${CP} ${WRKSRC}/config/database.yml.mysql ${WRKSRC}/config/database.yml.sample

post-patch-MYSQL-off:
	${REINPLACE_CMD} -e "/gem 'mysql2'/d" ${WRKSRC}/Gemfile
	${REINPLACE_CMD} -e "/gem 'peek-mysql2'/d" ${WRKSRC}/Gemfile

post-patch-PGSQL-on:
	${CP} ${WRKSRC}/config/database.yml.postgresql ${WRKSRC}/config/database.yml.sample

post-patch-PGSQL-off:
	${REINPLACE_CMD} -e "/gem 'pg'/d" ${WRKSRC}/Gemfile
	${REINPLACE_CMD} -e "/gem 'peek-pg'/d" ${WRKSRC}/Gemfile

do-install:
	(cd ${WRKSRC} && ${RM} Gemfile.lock && bundle install --local)
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete
	${FIND} ${WRKSRC} -name '*.gitkeep' -delete
	${FIND} ${WRKSRC} -name '*.gitignore' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	${MV} ${WRKSRC}/config/gitlab.yml.example ${WRKSRC}/config/gitlab.yml.sample
	${MV} ${WRKSRC}/config/unicorn.rb.example ${WRKSRC}/config/unicorn.rb.sample
	${MV} ${WRKSRC}/config/resque.yml.example ${WRKSRC}/config/resque.yml.sample
	${MV} ${WRKSRC}/config/secrets.yml.example ${WRKSRC}/config/secrets.yml.sample
	${MV} ${WRKSRC}/config/initializers/rack_attack.rb.example ${WRKSRC}/config/initializers/rack_attack.rb.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab ${WRKSRC}/lib/support/nginx/gitlab.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab-ssl ${WRKSRC}/lib/support/nginx/gitlab-ssl.sample
	${MKDIR} ${STAGEDIR}/usr/home/git/repositories
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/assets
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/uploads
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/cache
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/sessions
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/backups
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/tmp
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/artifacts/tmp/work
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

.include <bsd.port.mk>
