# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	gitlab-ce
PORTVERSION?=	13.9.2
PORTREVISION?=	0
CATEGORIES=	www devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Web GUI for managing git repositories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# the rubygems of RUN_DEPENDS matches the order of the Gemfile
# which makes maintaining this long list much easier!
MY_DEPENDS=	git>=2.29:devel/git \
	gitaly>=${PORTVERSION}:devel/gitaly \
	gitlab-elasticsearch-indexer>=2.9.0:textproc/gitlab-elasticsearch-indexer \
	gitlab-agent>=13.9.1:net/gitlab-agent \
	gitlab-pages>=1.35.0:www/gitlab-pages \
	gitlab-shell>=13.16.1:devel/gitlab-shell \
	gitlab-workhorse>=8.63.2:www/gitlab-workhorse \
	redis>=4.0.0:databases/redis \
	yarn>=1.10.0:www/yarn \
	gtar>0:archivers/gtar \
	bash>0:shells/bash \
	rubygem-rails60>=6.0.3.3<6.1:www/rubygem-rails60 \
	rubygem-bootsnap14>=1.4.6<2.0:devel/rubygem-bootsnap14 \
	rubygem-responders-rails60>=3.0<4.0:www/rubygem-responders-rails60 \
	rubygem-sprockets3>=3.7<3.8:devel/rubygem-sprockets3 \
	rubygem-default_value_for>=3.4.0<3.5.0:devel/rubygem-default_value_for \
	rubygem-pg>=1.2.3<2:databases/rubygem-pg \
	rubygem-rugged>=1.0.1<1.1:devel/rubygem-rugged \
	rubygem-grape-path-helpers>=1.6.1<1.7:devel/rubygem-grape-path-helpers \
	rubygem-faraday>=1.0<2:www/rubygem-faraday \
	rubygem-marginalia>=1.10.0<1.11:databases/rubygem-marginalia \
	rubygem-devise-rails60>=4.7.2<4.8:devel/rubygem-devise-rails60 \
	rubygem-bcrypt>=3.1.12<3.2:security/rubygem-bcrypt \
	rubygem-doorkeeper>=5.5.0.rc2<5.6:security/rubygem-doorkeeper \
	rubygem-doorkeeper-openid_connect>=1.7.5<1.8:security/rubygem-doorkeeper-openid_connect \
	rubygem-omniauth>=1.8<2.0:security/rubygem-omniauth \
	rubygem-omniauth-auth0>=2.0.0<2.1.0:net/rubygem-omniauth-auth0 \
	rubygem-omniauth-azure-oauth2>=0.0.9<0.1.0:net/rubygem-omniauth-azure-oauth2 \
	rubygem-omniauth-cas3>=1.1.4<1.2.0:security/rubygem-omniauth-cas3 \
	rubygem-omniauth-facebook4>=4.0.0<4.1.0:net/rubygem-omniauth-facebook4 \
	rubygem-omniauth-github>=1.4.0<2.0:net/rubygem-omniauth-github \
	rubygem-omniauth-gitlab>=1.0.2<1.1.0:security/rubygem-omniauth-gitlab \
	rubygem-omniauth-google-oauth2>=0.6.0<0.7.0:net/rubygem-omniauth-google-oauth2 \
	rubygem-omniauth-kerberos>=0.3.0<0.4.0:net/rubygem-omniauth-kerberos \
	rubygem-omniauth-oauth2-generic>=0.2.2<0.3.0:security/rubygem-omniauth-oauth2-generic \
	rubygem-omniauth-saml>=1.10<2.0:security/rubygem-omniauth-saml \
	rubygem-omniauth-shibboleth>=1.3.0<1.4.0:security/rubygem-omniauth-shibboleth \
	rubygem-omniauth-twitter>=1.4<2.0:net/rubygem-omniauth-twitter \
	rubygem-omniauth_crowd>=2.4.0<2.5:devel/rubygem-omniauth_crowd \
	rubygem-omniauth-authentiq>=0.3.3<0.4.0:net/rubygem-omniauth-authentiq \
	rubygem-omniauth_openid_connect>=0.3.5<0.4.0:net/rubygem-omniauth_openid_connect \
	rubygem-omniauth-ultraauth>=0.0.2<0.1.0:net/rubygem-omniauth-ultraauth \
	rubygem-omniauth-salesforce>=1.0.5<1.1.0:net/rubygem-omniauth-salesforce \
	rubygem-omniauth-atlassian-oauth2>=0.2.0<0.3:security/rubygem-omniauth-atlassian-oauth2 \
	rubygem-rack-oauth2>=1.16.0<1.17.0:security/rubygem-rack-oauth2 \
	rubygem-jwt21>=2.1.0<2.2.0:www/rubygem-jwt21 \
	rubygem-gssapi>0:security/rubygem-gssapi \
	rubygem-recaptcha>=4.11<5.0:devel/rubygem-recaptcha \
	rubygem-akismet>=3.0<4.0:devel/rubygem-akismet \
	rubygem-invisible_captcha>=1.1.0<1.2.0:graphics/rubygem-invisible_captcha \
	rubygem-devise-two-factor-rails60>=3.1.0<3.2.0:security/rubygem-devise-two-factor-rails60 \
	rubygem-rqrcode-rails3>=0.1.7<0.2.0:www/rubygem-rqrcode-rails3 \
	rubygem-attr_encrypted>=3.1.0<3.2.0:security/rubygem-attr_encrypted \
	rubygem-u2f0>=0.2.1<0.3.0:net/rubygem-u2f0 \
	rubygem-validates_hostname>=1.0.11<1.1.0:dns/rubygem-validates_hostname \
	rubygem-rubyzip20>=2.0.0<2.1.0:archivers/rubygem-rubyzip20 \
	rubygem-acme-client>=2.0.6<3:security/rubygem-acme-client \
	rubygem-browser>=4.2<5.0:www/rubygem-browser \
	rubygem-gpgme>=2.0.20<2.1.0:security/rubygem-gpgme \
	rubygem-gitlab_omniauth-ldap>=2.1.1<2.2.0:net/rubygem-gitlab_omniauth-ldap \
	rubygem-net-ldap>0.16.3:net/rubygem-net-ldap \
	rubygem-grape>=1.5.2<1.6:devel/rubygem-grape \
	rubygem-grape-entity07>=0.7.1<0.8.0,1:devel/rubygem-grape-entity07 \
	rubygem-rack-cors>=1.0.6<1.1.0:www/rubygem-rack-cors \
	rubygem-graphql>=1.11.4<1.12:devel/rubygem-graphql \
	rubygem-graphiql-rails>=1.4.10<1.5.0:devel/rubygem-graphiql-rails \
	rubygem-apollo_upload_server>=2.0.2<2.1:net/rubygem-apollo_upload_server \
	rubygem-graphql-docs>=1.6.0<1.7.0:devel/rubygem-graphql-docs \
	rubygem-graphlient>=0.4.0<0.5:devel/rubygem-graphlient \
	rubygem-hashie>0:devel/rubygem-hashie \
	rubygem-hashie-forbidden_attributes>0:devel/rubygem-hashie-forbidden_attributes \
	rubygem-kaminari-rails60>=1.2.1<2.0:www/rubygem-kaminari-rails60 \
	rubygem-hamlit>=2.14.4<2.15:www/rubygem-hamlit \
	rubygem-carrierwave>=1.3<2.0:www/rubygem-carrierwave \
	rubygem-mini_magick>=4.10.1<4.11:graphics/rubygem-mini_magick \
	rubygem-fog-aws>=3.8<4.0:net/rubygem-fog-aws \
	rubygem-fog-core210=2.1.0:devel/rubygem-fog-core210 \
	rubygem-fog-google>=1.12<2:net/rubygem-fog-google \
	rubygem-fog-local>=0.6<1.0:net/rubygem-fog-local \
	rubygem-fog-openstack>=1.0<2.0:net/rubygem-fog-openstack \
	rubygem-fog-rackspace>=0.1.1<1.2.0:net/rubygem-fog-rackspace \
	rubygem-fog-aliyun>=0.3<1.0:net/rubygem-fog-aliyun \
	rubygem-gitlab-fog-azure-rm>=1.0<2:net/rubygem-gitlab-fog-azure-rm \
	rubygem-google-api-client>=0.33<1:devel/rubygem-google-api-client \
	rubygem-unf>=0.1.4<0.2.0:textproc/rubygem-unf \
	rubygem-seed-fu>=2.3.7<2.4.0:databases/rubygem-seed-fu \
	rubygem-elasticsearch-model6>=6.1.1<7:textproc/rubygem-elasticsearch-model6 \
	rubygem-elasticsearch-rails6>=6.1.1<7:textproc/rubygem-elasticsearch-rails6 \
	rubygem-elasticsearch-api6>=6.8.2<6.9:textproc/rubygem-elasticsearch-api6 \
	rubygem-aws-sdk-core>=3<4:devel/rubygem-aws-sdk-core \
	rubygem-aws-sdk-cloudformation>=1<2:devel/rubygem-aws-sdk-cloudformation \
	rubygem-aws-sdk-s3>=1<2:devel/rubygem-aws-sdk-s3 \
	rubygem-faraday_middleware-aws-sigv403>=0.3.0<0.4:devel/rubygem-faraday_middleware-aws-sigv403 \
	rubygem-html-pipeline>=2.13.2<2.14:textproc/rubygem-html-pipeline \
	rubygem-deckar01-task_list=2.3.1:www/rubygem-deckar01-task_list \
	rubygem-gitlab-markup>=1.7.1<1.8.0:textproc/rubygem-gitlab-markup \
	rubygem-github-markup17>=1.7.0<1.8.0:textproc/rubygem-github-markup17 \
	rubygem-commonmarker>=0.21<1.0:textproc/rubygem-commonmarker \
	rubygem-kramdown>=2.3.0<2.4:textproc/rubygem-kramdown \
	rubygem-redcloth>=4.3.2<4.4.0:www/rubygem-redcloth \
	rubygem-rdoc>=6.1.2<7:devel/rubygem-rdoc \
	rubygem-org-ruby>=0.9.12<0.10.0:textproc/rubygem-org-ruby \
	rubygem-creole>=0.5.0<0.6.0:textproc/rubygem-creole \
	rubygem-wikicloth081>=0.8.1<0.8.2:textproc/rubygem-wikicloth081 \
	rubygem-asciidoctor>=2.0.12<2.1.0:textproc/rubygem-asciidoctor \
	rubygem-asciidoctor-include-ext>=0.3.1<0.4.0:textproc/rubygem-asciidoctor-include-ext \
	rubygem-asciidoctor-plantuml>=0.0.12<0.1:textproc/rubygem-asciidoctor-plantuml \
	rubygem-asciidoctor-kroki>=0.3.0<0.4:textproc/rubygem-asciidoctor-kroki \
	rubygem-rouge>=3.26.0<3.27:textproc/rubygem-rouge \
	rubygem-truncato>=0.7.11<0.8.0:textproc/rubygem-truncato \
	rubygem-bootstrap_form>=4.2.0<4.3.0:devel/rubygem-bootstrap_form \
	rubygem-nokogiri>=1.11.1<1.12:textproc/rubygem-nokogiri \
	rubygem-escape_utils>=1.1<2.0:textproc/rubygem-escape_utils \
	rubygem-icalendar>=0:devel/rubygem-icalendar \
	rubygem-diffy>=3.3<4:textproc/rubygem-diffy \
	rubygem-diff_match_patch>=0.1.0<0.2.0:textproc/rubygem-diff_match_patch \
	rubygem-rack>=2.2.3<2.3,3:www/rubygem-rack \
	rubygem-rack-timeout>=0.5.1<0.6:www/rubygem-rack-timeout \
	rubygem-unicorn>=5.5<6:www/rubygem-unicorn \
	rubygem-unicorn-worker-killer>=0.4.4<0.5.0:www/rubygem-unicorn-worker-killer \
	rubygem-puma>=5.1.1:www/rubygem-puma \
	rubygem-puma_worker_killer>=0.3.1:www/rubygem-puma_worker_killer \
	rubygem-state_machines-activerecord>=0.8.0<0.9.0:databases/rubygem-state_machines-activerecord \
	rubygem-acts-as-taggable-on>=7.0<8.0:www/rubygem-acts-as-taggable-on \
	rubygem-sidekiq5>=5.2.9<5.3.0:devel/rubygem-sidekiq5 \
	rubygem-sidekiq-cron>=1.0<2.0:devel/rubygem-sidekiq-cron \
	rubygem-redis-namespace17>=1.7.0<1.8.0:databases/rubygem-redis-namespace17 \
	rubygem-gitlab-sidekiq-fetcher=0.5.2_1:devel/rubygem-gitlab-sidekiq-fetcher \
	rubygem-fugit12>=1.2.1<1.3.0:devel/rubygem-fugit12 \
	rubygem-httparty>=0.16.4<0.17.0:www/rubygem-httparty \
	rubygem-rainbow>=3.0<4.0:devel/rubygem-rainbow \
	rubygem-ruby-progressbar>=1.11<2:devel/rubygem-ruby-progressbar \
	rubygem-settingslogic>=2.0.9<2.1.0:devel/rubygem-settingslogic \
	rubygem-re2>=1.2.0<1.3.0:devel/rubygem-re2 \
	rubygem-version_sorter>=2.2.4<2.3.0:textproc/rubygem-version_sorter \
	rubygem-js_regex>=3.4<4.0:textproc/rubygem-js_regex \
	rubygem-device_detector>=0:devel/rubygem-device_detector \
	rubygem-redis>=4.0<5.0:databases/rubygem-redis \
	rubygem-connection_pool>=2.0<3.0:net/rubygem-connection_pool \
	rubygem-redis-rails-rails60>=5.0.2<5.1:www/rubygem-redis-rails-rails60 \
	rubygem-discordrb-webhooks-blackst0ne>=3.3<4.0:net-im/rubygem-discordrb-webhooks-blackst0ne \
	rubygem-hipchat>=1.6.0<1.7.0:net-im/rubygem-hipchat \
	rubygem-jira-ruby>=2.1.4<2.2:devel/rubygem-jira-ruby \
	rubygem-atlassian-jwt>=0.2.0<0.3.0:www/rubygem-atlassian-jwt \
	rubygem-flowdock>=0.7<1.0:www/rubygem-flowdock \
	rubygem-slack-messenger>=2.3.4<2.4.0:devel/rubygem-slack-messenger \
	rubygem-hangouts-chat>=0.0.5<0.1.0:net/rubygem-hangouts-chat \
	rubygem-asana>=0.10.3<0.11:www/rubygem-asana \
	rubygem-ruby-fogbugz021>=0.2.1<0.3.0:devel/rubygem-ruby-fogbugz021 \
	rubygem-kubeclient>=4.9.1<4.10.0:www/rubygem-kubeclient \
	rubygem-sanitize>=5.2.1<6:textproc/rubygem-sanitize \
	rubygem-babosa>=1.0.2<1.1.0:textproc/rubygem-babosa \
	rubygem-loofah>=2.8<3.0:textproc/rubygem-loofah \
	rubygem-licensee>=9.14.1<9.15:devel/rubygem-licensee \
	rubygem-charlock_holmes>=0.7.7<0.8.0:textproc/rubygem-charlock_holmes \
	rubygem-mimemagic>=0.3.2<0.4.0:misc/rubygem-mimemagic \
	rubygem-fast_blank>=0:devel/rubygem-fast_blank \
	rubygem-gitlab-chronic>=0.10.5<0.11.0:devel/rubygem-gitlab-chronic \
	rubygem-gitlab_chronic_duration>=0.10.6.2<0.10.7:devel/rubygem-gitlab_chronic_duration \
	rubygem-rack-proxy>=0.6.0<0.7.0:www/rubygem-rack-proxy \
	rubygem-sassc-rails-rails60>=2.1.0<2.2.0:textproc/rubygem-sassc-rails-rails60 \
	rubygem-autoprefixer-rails>=10.2.0.0<10.2.1:textproc/rubygem-autoprefixer-rails \
	rubygem-terser>=1.0.2:textproc/rubygem-terser \
	rubygem-addressable>=2.7<3:www/rubygem-addressable \
	rubygem-gemojione>=3.3<4.0:graphics/rubygem-gemojione \
	rubygem-gon-rails60>=6.2<7.0:www/rubygem-gon-rails60 \
	rubygem-request_store>=1.5<2.0:devel/rubygem-request_store \
	rubygem-base32>=0.3.0<0.4.0:converters/rubygem-base32 \
	rubygem-gitlab-license>=1.3<2.0:devel/rubygem-gitlab-license \
	rubygem-rack-attack>=6.3.0<6.4.0:www/rubygem-rack-attack \
	rubygem-sentry-raven>=3.0<4.0:devel/rubygem-sentry-raven \
	rubygem-pg_query>=1.3.0<1.4:databases/rubygem-pg_query \
	rubygem-premailer-rails-rails60>=1.10.3<1.11.0:mail/rubygem-premailer-rails-rails60 \
	rubygem-gitlab-labkit>=0.14.0<0.16:devel/rubygem-gitlab-labkit \
	rubygem-thrift>=0.14.0:devel/rubygem-thrift \
	rubygem-ruby_parser>=3.15<4.0:devel/rubygem-ruby_parser \
	rubygem-rails-i18n-rails60>=6.0<7.0:devel/rubygem-rails-i18n-rails60 \
	rubygem-gettext_i18n_rails>=1.8.0<1.9.0:devel/rubygem-gettext_i18n_rails \
	rubygem-gettext_i18n_rails_js-rails60>=1.3<2.0:devel/rubygem-gettext_i18n_rails_js-rails60 \
	rubygem-gettext>=3.3<4:devel/rubygem-gettext \
	rubygem-batch-loader14>=1.4.0<1.5.0:devel/rubygem-batch-loader14 \
	rubygem-peek-rails60>=1.1.0<2.0:devel/rubygem-peek-rails60 \
	rubygem-snowplow-tracker>=0.6.1<0.7.0:devel/rubygem-snowplow-tracker \
	rubygem-method_source>=1.0<2:devel/rubygem-method_source \
	rubygem-webrick>=1.6.1:www/rubygem-webrick \
	rubygem-prometheus-client-mmap>=0.12.0<0.13.0:devel/rubygem-prometheus-client-mmap \
	rubygem-raindrops>=0.18<1.0:www/rubygem-raindrops \
	rubygem-octokit>=4.20<5.0:net/rubygem-octokit \
	rubygem-gitlab-mail_room>=0.0.8<0.1.0:mail/rubygem-gitlab-mail_room \
	rubygem-email_reply_trimmer>=0.1<1.0:mail/rubygem-email_reply_trimmer \
	rubygem-html2text>=0:textproc/rubygem-html2text \
	rubygem-ruby-prof>=1.3.0<1.4.0:devel/rubygem-ruby-prof \
	rubygem-stackprof>=0.2.15<0.3:devel/rubygem-stackprof \
	rubygem-rbtrace>=0.4.14<1.0:devel/rubygem-rbtrace \
	rubygem-memory_profiler>=0.9<1.0:devel/rubygem-memory_profiler \
	rubygem-benchmark-memory>=0.1<1.0:benchmarks/rubygem-benchmark-memory \
	rubygem-activerecord-explain-analyze>=0.1<1.0:databases/rubygem-activerecord-explain-analyze \
	rubygem-oauth2>=1.4.4<2.0:net/rubygem-oauth2 \
	rubygem-health_check>=3.0<4:devel/rubygem-health_check \
	rubygem-vmstat>=2.3.0<2.4.0:sysutils/rubygem-vmstat \
	rubygem-sys-filesystem>=1.1.6<1.2.0:sysutils/rubygem-sys-filesystem \
	rubygem-net-ntp>0:net/rubygem-net-ntp \
	rubygem-net-ssh>=6.0<7,2:security/rubygem-net-ssh \
	rubygem-sshkey>=2.0<3.0:security/rubygem-sshkey \
	rubygem-ed25519>=1.2<2.0:security/rubygem-ed25519 \
	rubygem-bcrypt_pbkdf>=1.0<2.0:security/rubygem-bcrypt_pbkdf \
	rubygem-gitaly>=13.9.0.pre.rc1<13.10.0:net/rubygem-gitaly \
	rubygem-grpc130>=1.30.2<1.31:net/rubygem-grpc130 \
	rubygem-google-protobuf>=3.12<3.15:devel/rubygem-google-protobuf \
	rubygem-toml-rb10>=1.0.0<1.1.0:www/rubygem-toml-rb10 \
	rubygem-flipper017>=0.17.1<0.18.0:devel/rubygem-flipper017 \
	rubygem-flipper-active_record017>=0.17.1<0.18.0:databases/rubygem-flipper-active_record017 \
	rubygem-flipper-active_support_cache_store017>=0.17.1<0.18.0:devel/rubygem-flipper-active_support_cache_store017 \
	rubygem-unleash>=0.1.5<0.2.0:devel/rubygem-unleash \
	rubygem-gitlab-experiment>=0.4.9<0.5:devel/rubygem-gitlab-experiment \
	rubygem-lograge-rails60>=0.11.2<1.0:www/rubygem-lograge-rails60 \
	rubygem-grape_logging>=1.7<2.0:devel/rubygem-grape_logging \
	rubygem-gitlab-net-dns>=0.9.1<0.10:dns/rubygem-gitlab-net-dns \
	rubygem-countries>=3.0.0<4.0.0:devel/rubygem-countries \
	rubygem-retriable>=3.1.2<3.2.0:devel/rubygem-retriable \
	rubygem-lru_redux>0:devel/rubygem-lru_redux \
	rubygem-erubi19>=1.9.0<1.10:www/rubygem-erubi19 \
	rubygem-mail>=2.7.1<2.7.2,2:mail/rubygem-mail \
	rubygem-lockbox>=0.3.3<0.4.0:security/rubygem-lockbox \
	rubygem-valid_email>=0.1<1:mail/rubygem-valid_email \
	rubygem-json>=2.3.0<2.4:devel/rubygem-json \
	rubygem-json-schema>=2.8.0<2.9:devel/rubygem-json-schema \
	rubygem-json_schemer>=0.2.12<0.3:devel/rubygem-json_schemer \
	rubygem-oj310>=3.10.6<3.11:devel/rubygem-oj310 \
	rubygem-multi_json114>=1.14.1<1.15:devel/rubygem-multi_json114 \
	rubygem-yajl-ruby>=1.4.1<1.5:devel/rubygem-yajl-ruby \
	rubygem-webauthn>=2.3<3:security/rubygem-webauthn \
	rubygem-ipaddress>=0.8.3<0.9:net/rubygem-ipaddress \
	rubygem-parslet1>=1.8<2:textproc/rubygem-parslet1

BUILD_DEPENDS=	gem:devel/ruby-gems \
	${MY_DEPENDS}

RUN_DEPENDS=	${MY_DEPENDS}

CONFLICTS_INSTALL=	gitolite-* \
			gitolite2-* \
			gogs-* \
			gitea-* \
			${PYTHON_PKGNAMEPREFIX}-gitosis-*

USES=		shebangfix
USE_RUBY=	yes

USE_RC_SUBR=	gitlab
USE_GITLAB=	yes
GL_ACCOUNT?=	gitlab-org
GL_PROJECT?=	gitlab-foss
# Find the here: https://gitlab.com/gitlab-org/gitlab-foss/-/tags
GL_COMMIT?=	189a15a911843a9059d1f8bfd31008557bea520b

USERS=	git
GROUPS=	git

NO_BUILD=	yes

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config/gitlab.yml.example \
		${WRKSRC}/config/puma.rb.example \
		${WRKSRC}/config/unicorn.rb.example \
		${WRKSRC}/lib/support/nginx/gitlab \
		${WRKSRC}/lib/support/nginx/gitlab-ssl

do-install:
	${CP} ${WRKSRC}/config/database.yml.postgresql ${WRKSRC}/config/database.yml.sample
	(cd ${WRKSRC} && ${RM} Gemfile.lock && bundle install --local)
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete
	${FIND} ${WRKSRC} -name '*.gitkeep' -delete
	${FIND} ${WRKSRC} -name '*.gitignore' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	# get files for workdir with: find . -name "*.example"
	${MV} ${WRKSRC}/config/puma.rb.example ${WRKSRC}/config/puma.rb.sample
	${MV} ${WRKSRC}/config/secrets.yml.example ${WRKSRC}/config/secrets.yml.sample
	${MV} ${WRKSRC}/config/redis.cache.yml.example ${WRKSRC}/config/redis.cache.yml.sample
	${MV} ${WRKSRC}/config/sidekiq.yml.example ${WRKSRC}/config/sidekiq.yml.sample
	${MV} ${WRKSRC}/config/cable.yml.example ${WRKSRC}/config/cable.yml.sample
	${MV} ${WRKSRC}/config/gitlab.yml.example ${WRKSRC}/config/gitlab.yml.sample
	${MV} ${WRKSRC}/config/redis.queues.yml.example ${WRKSRC}/config/redis.queues.yml.sample
	${MV} ${WRKSRC}/config/initializers/devise_password_length.rb.example ${WRKSRC}/config/initializers/devise_password_length.rb.sample
	${MV} ${WRKSRC}/config/redis.shared_state.yml.example ${WRKSRC}/config/redis.shared_state.yml.sample
	${MV} ${WRKSRC}/config/unicorn.rb.example ${WRKSRC}/config/unicorn.rb.sample
	${MV} ${WRKSRC}/config/resque.yml.example ${WRKSRC}/config/resque.yml.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab ${WRKSRC}/lib/support/nginx/gitlab.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab-ssl ${WRKSRC}/lib/support/nginx/gitlab-ssl.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/assets
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/uploads
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/cache
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/sessions
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/backups
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/tmp
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/artifacts/tmp/work
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/vendor/assets/stylesheets
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/workhorse/changelogs/unreleased
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

.include <bsd.port.mk>
