# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-ce
PORTVERSION=	12.0.3
PORTREVISION=	2
CATEGORIES=	www devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Web GUI for managing git repositories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# the rubygems of RUN_DEPENDS matches the order of the Gemfile
# which makes maintaining this long list much easier!
# only rubygem-pg and rubygem-mysql are defined later as RUN_DEPENDS
# for the options
MY_DEPENDS=	git>=2.21.0:devel/git \
	gitlab-shell>=9.3.0:devel/gitlab-shell \
	gitlab-workhorse>=8.7.0:www/gitlab-workhorse \
	gitaly>=1.47.0:devel/gitaly \
	gitlab-pages>=1.6.1:www/gitlab-pages \
	redis>=3.2.12:databases/redis \
	yarn>=1.10.0:www/yarn \
	rubygem-rails5>=5.1.7:www/rubygem-rails5 \
	rubygem-nakayoshi_fork>=0.0.4:devel/rubygem-nakayoshi_fork \
	rubygem-responders2-rails5>=2.0:www/rubygem-responders2-rails5 \
	rubygem-sprockets3>=3.7:devel/rubygem-sprockets3 \
	rubygem-gitlab-default_value_for>=3.1.1:devel/rubygem-gitlab-default_value_for \
	rubygem-rugged>=0.28.0:devel/rubygem-rugged \
	rubygem-grape-path-helpers>=1.1:devel/rubygem-grape-path-helpers \
	rubygem-faraday>=0.12.0:www/rubygem-faraday \
	rubygem-devise-rails5>=4.6:devel/rubygem-devise-rails5 \
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
	rubygem-omniauth_openid_connect>=0.3.1:net/rubygem-omniauth_openid_connect \
	rubygem-omniauth-ultraauth>=0.0.2:net/rubygem-omniauth-ultraauth \
	rubygem-omniauth-salesforce>=1.0.5:net/rubygem-omniauth-salesforce \
	rubygem-rack-oauth2>=1.9.3:security/rubygem-rack-oauth2 \
	rubygem-jwt21>=2.1.0:www/rubygem-jwt21 \
	rubygem-recaptcha>=4.11:devel/rubygem-recaptcha \
	rubygem-akismet>=2.0:devel/rubygem-akismet \
	rubygem-devise-two-factor-rails5>=3.0.0:security/rubygem-devise-two-factor-rails5 \
	rubygem-rqrcode-rails3>=0.1.7:www/rubygem-rqrcode-rails3 \
	rubygem-attr_encrypted>=3.1.0:security/rubygem-attr_encrypted \
	rubygem-u2f0>=0.2.1:net/rubygem-u2f0 \
	rubygem-validates_hostname>=1.0.6:dns/rubygem-validates_hostname \
	rubygem-rubyzip>=1.2.2:archivers/rubygem-rubyzip \
	rubygem-acme-client>=2.0.2:security/rubygem-acme-client \
	rubygem-browser>=2.5:www/rubygem-browser \
	rubygem-gpgme>=2.0.18:security/rubygem-gpgme \
	rubygem-gitlab_omniauth-ldap>=2.1.1:net/rubygem-gitlab_omniauth-ldap \
	rubygem-net-ldap>=0.16.0:net/rubygem-net-ldap \
	rubygem-grape11>=1.1:devel/rubygem-grape11 \
	rubygem-grape-entity>=0.7.1:devel/rubygem-grape-entity \
	rubygem-rack-cors>=1.0.0:www/rubygem-rack-cors \
	rubygem-graphql>=1.8.0:devel/rubygem-graphql \
	rubygem-graphiql-rails>=1.4.10:devel/rubygem-graphiql-rails \
	rubygem-apollo_upload_server>=2.0.0.b.3:net/rubygem-apollo_upload_server \
	rubygem-hashie-forbidden_attributes>=0:devel/rubygem-hashie-forbidden_attributes \
	rubygem-kaminari-rails5>=1.0:www/rubygem-kaminari-rails5 \
	rubygem-hamlit>=2.8.8:www/rubygem-hamlit \
	rubygem-carrierwave>=1.3.0:www/rubygem-carrierwave \
	rubygem-mini_magick>=0:graphics/rubygem-mini_magick \
	rubygem-fog-aws>=3.3:net/rubygem-fog-aws \
	rubygem-fog-core210>=2.1.0:devel/rubygem-fog-core210 \
	rubygem-fog-google>=1.8:net/rubygem-fog-google \
	rubygem-fog-local>=0.6:net/rubygem-fog-local \
	rubygem-fog-openstack>=1.0:net/rubygem-fog-openstack \
	rubygem-fog-rackspace>=0.1.1:net/rubygem-fog-rackspace \
	rubygem-fog-aliyun>=0.3:net/rubygem-fog-aliyun \
	rubygem-google-api-client>=0.23:devel/rubygem-google-api-client \
	rubygem-unf>=0.1.4:textproc/rubygem-unf \
	rubygem-seed-fu>=2.3.7:databases/rubygem-seed-fu \
	rubygem-html-pipeline>=2.8:textproc/rubygem-html-pipeline \
	rubygem-deckar01-task_list>=2.2.0:www/rubygem-deckar01-task_list \
	rubygem-gitlab-markup>=1.7.0:textproc/rubygem-gitlab-markup \
	rubygem-github-markup17>=1.7.0:textproc/rubygem-github-markup17 \
	rubygem-commonmarker>=0.17:textproc/rubygem-commonmarker \
	rubygem-redcloth>=4.3.2:www/rubygem-redcloth \
	rubygem-rdoc>=6.0:devel/rubygem-rdoc \
	rubygem-org-ruby>=0.9.12:textproc/rubygem-org-ruby \
	rubygem-creole>=0.5.0:textproc/rubygem-creole \
	rubygem-wikicloth081>=0.8.1:textproc/rubygem-wikicloth081 \
	rubygem-asciidoctor>=1.5.8:textproc/rubygem-asciidoctor \
	rubygem-asciidoctor-include-ext>=0.3.1:textproc/rubygem-asciidoctor-include-ext \
	rubygem-asciidoctor-plantuml008>=0.0.8:textproc/rubygem-asciidoctor-plantuml008 \
	rubygem-rouge>=3.1:textproc/rubygem-rouge \
	rubygem-truncato>=0.7.11:textproc/rubygem-truncato \
	rubygem-bootstrap_form>=4.2.0:devel/rubygem-bootstrap_form \
	rubygem-nokogiri>=1.10.3:textproc/rubygem-nokogiri \
	rubygem-escape_utils>=1.1:textproc/rubygem-escape_utils \
	rubygem-icalendar>=0:devel/rubygem-icalendar \
	rubygem-diffy31>=3.1.0:textproc/rubygem-diffy31 \
	rubygem-rack>=2.0.7:www/rubygem-rack \
	rubygem-unicorn>=5.4.1:www/rubygem-unicorn \
	rubygem-unicorn-worker-killer>=0.4.4:www/rubygem-unicorn-worker-killer \
	rubygem-puma>=3.12:www/rubygem-puma \
	rubygem-puma_worker_killer>=0:www/rubygem-puma_worker_killer \
	rubygem-rack-timeout>=0:www/rubygem-rack-timeout \
	rubygem-state_machines-activerecord05>=0.5.1:databases/rubygem-state_machines-activerecord05 \
	rubygem-acts-as-taggable-on>=6.0:www/rubygem-acts-as-taggable-on \
	rubygem-sidekiq>=5.2.7:devel/rubygem-sidekiq \
	rubygem-sidekiq-cron>=1.0.0:devel/rubygem-sidekiq-cron \
	rubygem-redis-namespace>=1.6.0:databases/rubygem-redis-namespace \
	rubygem-gitlab-sidekiq-fetcher>=0.4.0:devel/rubygem-gitlab-sidekiq-fetcher \
	rubygem-fugit12>=1.2.1:devel/rubygem-fugit12 \
	rubygem-httparty>=0.16.4:www/rubygem-httparty \
	rubygem-rainbow>=3.0:devel/rubygem-rainbow \
	rubygem-ruby-progressbar>=0:devel/rubygem-ruby-progressbar \
	rubygem-settingslogic>=2.0.9:devel/rubygem-settingslogic \
	rubygem-re2>=1.1.1:devel/rubygem-re2 \
	rubygem-version_sorter>=2.2.4:textproc/rubygem-version_sorter \
	rubygem-js_regex>=3.1.0:textproc/rubygem-js_regex \
	rubygem-device_detector>=0:devel/rubygem-device_detector \
	rubygem-redis-rails-rails5>=5.0.1:www/rubygem-redis-rails-rails5 \
	rubygem-redis3>=3.2:databases/rubygem-redis3 \
	rubygem-connection_pool>=2.0:net/rubygem-connection_pool \
	rubygem-discordrb-webhooks-blackst0ne>=3.3.0:net-im/rubygem-discordrb-webhooks-blackst0ne \
	rubygem-hipchat>=1.5.0:net-im/rubygem-hipchat \
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
	rubygem-webpack-rails-rails5>=0.9.10:www/rubygem-webpack-rails-rails5 \
	rubygem-rack-proxy>=0.6.0:www/rubygem-rack-proxy \
	rubygem-sassc-rails>=2.1.0:textproc/rubygem-sassc-rails \
	rubygem-uglifier27>=2.7.2:www/rubygem-uglifier27 \
	rubygem-addressable25>=2.5.2:www/rubygem-addressable25 \
	rubygem-font-awesome-rails-rails5>=4.7:devel/rubygem-font-awesome-rails-rails5 \
	rubygem-gemojione>=3.3:graphics/rubygem-gemojione \
	rubygem-gon-rails5>=6.2.0:www/rubygem-gon-rails5 \
	rubygem-request_store>=1.3:devel/rubygem-request_store \
	rubygem-virtus>=1.0.1:devel/rubygem-virtus \
	rubygem-base32>=0.3.0:converters/rubygem-base32 \
	rubygem-sentry-raven>=2.9:devel/rubygem-sentry-raven \
	rubygem-premailer-rails19-rails5>=1.9.7:mail/rubygem-premailer-rails19-rails5 \
	rubygem-gitlab-labkit>=0.3.0:devel/rubygem-gitlab-labkit \
	rubygem-ruby_parser>=3.8.4:devel/rubygem-ruby_parser \
	rubygem-rails-i18n-rails5>=5.1.0:devel/rubygem-rails-i18n-rails5 \
	rubygem-gettext_i18n_rails>=1.8.0:devel/rubygem-gettext_i18n_rails \
	rubygem-gettext_i18n_rails_js-rails5>=1.3:devel/rubygem-gettext_i18n_rails_js-rails5 \
	rubygem-gettext>=3.2.2:devel/rubygem-gettext \
	rubygem-batch-loader>=1.4.0:devel/rubygem-batch-loader \
	rubygem-peek-rails5>=1.0.1:devel/rubygem-peek-rails5 \
	rubygem-peek-gc-rails5>=0.0.2:devel/rubygem-peek-gc-rails5 \
	rubygem-peek-rblineprof-rails5>=0.2.0:devel/rubygem-peek-rblineprof-rails5 \
	rubygem-peek-redis-rails5>=1.2.0:devel/rubygem-peek-redis-rails5 \
	rubygem-method_source>=0.8:devel/rubygem-method_source \
	rubygem-influxdb>=0.2:databases/rubygem-influxdb \
	rubygem-prometheus-client-mmap>=0.9.4:devel/rubygem-prometheus-client-mmap \
	rubygem-octokit>=4.9:net/rubygem-octokit \
	rubygem-mail_room>=0.9.1:mail/rubygem-mail_room \
	rubygem-email_reply_trimmer>=0.1:mail/rubygem-email_reply_trimmer \
	rubygem-html2text>=0:textproc/rubygem-html2text \
	rubygem-ruby-prof>=0.17.0:devel/rubygem-ruby-prof \
	rubygem-rbtrace>=0.4:devel/rubygem-rbtrace \
	rubygem-memory_profiler>=0.9:devel/rubygem-memory_profiler \
	rubygem-benchmark-memory>=0.1:benchmarks/rubygem-benchmark-memory \
	rubygem-activerecord-explain-analyze>=0.1:databases/rubygem-activerecord-explain-analyze \
	rubygem-oauth2>=1.4.0:net/rubygem-oauth2 \
	rubygem-health_check26-rails5>=2.6.0:devel/rubygem-health_check26-rails5 \
	rubygem-vmstat>=2.3.0:sysutils/rubygem-vmstat \
	rubygem-sys-filesystem>=1.1.6:sysutils/rubygem-sys-filesystem \
	rubygem-net-ssh>=5.0:security/rubygem-net-ssh \
	rubygem-sshkey>=2.0:security/rubygem-sshkey \
	rubygem-ed25519>=1.2:security/rubygem-ed25519 \
	rubygem-bcrypt_pbkdf>=1.0:security/rubygem-bcrypt_pbkdf \
	rubygem-gitaly-proto>=1.32.0:net/rubygem-gitaly-proto \
	rubygem-grpc>=1.19.0:net/rubygem-grpc \
	rubygem-gitaly>=0.8.0:net/rubygem-gitaly \
	rubygem-google-protobuf371>=3.7.1:devel/rubygem-google-protobuf371 \
	rubygem-toml-rb10>=1.0.0:www/rubygem-toml-rb10 \
	rubygem-flipper013>=0.13.0:devel/rubygem-flipper013 \
	rubygem-flipper-active_record013>=0.13.0:databases/rubygem-flipper-active_record013 \
	rubygem-flipper-active_support_cache_store013>=0.13.0:devel/rubygem-flipper-active_support_cache_store013 \
	rubygem-lograge-rails5>=0.5:www/rubygem-lograge-rails5 \
	rubygem-grape_logging>=1.7:devel/rubygem-grape_logging

BUILD_DEPENDS=	gem:devel/ruby-gems \
	${MY_DEPENDS}

RUN_DEPENDS=	${MY_DEPENDS}

CONFLICTS_INSTALL=	gitolite-* \
			gitolite2-* \
			gogs-* \
			gitea-* \
			${PYTHON_PKGNAMEPREFIX}-gitosis-*

OPTIONS_SINGLE=	DATABASE
OPTIONS_SINGLE_DATABASE=	PGSQL MYSQL
OPTIONS_DEFAULT=	PGSQL
PGSQL_DESC=	Default PostgreSQL support (preferred)
MYSQL_DESC=	Optional MySQL support

PGSQL_RUN_DEPENDS=	rubygem-pg>=1.1.0:databases/rubygem-pg \
	rubygem-peek-pg-rails5>=1.3.0:databases/rubygem-peek-pg-rails5
MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0.4.5:databases/rubygem-mysql2 \
	rubygem-peek-mysql2-rails5>=1.2.0:databases/rubygem-peek-mysql2-rails5

USE_RUBY=	yes

USE_RC_SUBR=	gitlab
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the here: https://gitlab.com/gitlab-org/gitlab-ce/tags
GL_COMMIT=	08a51a9db938bb05f9a4c999075d010079e16bad

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
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/assets
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/uploads
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/cache
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/sessions
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/backups
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/tmp
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/artifacts/tmp/work
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

.include <bsd.port.mk>
