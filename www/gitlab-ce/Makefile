# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>

PORTNAME=	gitlab-ce
PORTVERSION=	14.7.3
PORTREVISION=	1
CATEGORIES=	www devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Web GUI for managing git repositories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# the rubygems of RUN_DEPENDS matches the order of the Gemfile
# which makes maintaining this long list much easier!
# devel/rubygem-parser is required for database upgrade process
# see https://gitlab.com/gitlab-org/gitlab/-/issues/350866
MY_DEPENDS=	git>=2.32.0:devel/git \
	gitaly>=${PORTVERSION}:devel/gitaly \
	gitlab-elasticsearch-indexer>=2.17.0:textproc/gitlab-elasticsearch-indexer \
	gitlab-agent>=14.4.0:net/gitlab-agent \
	gitlab-pages>=1.51.0:www/gitlab-pages \
	gitlab-shell>=13.22.2:devel/gitlab-shell \
	gitlab-workhorse>=${PORTVERSION}:www/gitlab-workhorse \
	redis>=6.0.14:databases/redis \
	yarn>=1.10.0:www/yarn \
	gtar>0:archivers/gtar \
	bash>0:shells/bash \
	rubygem-rails61>=6.1.4.4<6.1.5:www/rubygem-rails61 \
	rubygem-bootsnap>=1.9.1<1.11:devel/rubygem-bootsnap \
	rubygem-responders-rails61>=3.0<4.0:www/rubygem-responders-rails61 \
	rubygem-sprockets3>=3.7<3.8:devel/rubygem-sprockets3 \
	rubygem-default_value_for>=3.4.0<3.5.0:devel/rubygem-default_value_for \
	rubygem-pg>=1.2.3<2:databases/rubygem-pg \
	rubygem-rugged>=1.2<2:devel/rubygem-rugged \
	rubygem-grape-path-helpers>=1.7.0<1.8:devel/rubygem-grape-path-helpers \
	rubygem-faraday>=1.0<2:www/rubygem-faraday \
	rubygem-marginalia>=1.10.0<1.11:databases/rubygem-marginalia \
	rubygem-declarative_policy>=1.1.0<1.2:security/rubygem-declarative_policy \
	rubygem-devise47-rails61>=4.7.2<4.8:devel/rubygem-devise47-rails61 \
	rubygem-bcrypt>=3.1.14<3.2:security/rubygem-bcrypt \
	rubygem-doorkeeper>=5.5.0.rc2<5.6:security/rubygem-doorkeeper \
	rubygem-doorkeeper-openid_connect>=1.7.5<1.8:security/rubygem-doorkeeper-openid_connect \
	rubygem-rexml>=3.2.5<3.3:textproc/rubygem-rexml \
	rubygem-ruby-saml>=1.13.0<1.14:security/rubygem-ruby-saml \
	rubygem-omniauth1>=1.9.1<2.0:security/rubygem-omniauth1 \
	rubygem-omniauth-auth0>=2.0.0<2.1.0:net/rubygem-omniauth-auth0 \
	rubygem-omniauth-azure-activedirectory-v2>=1.0<2:net/rubygem-omniauth-azure-activedirectory-v2 \
	rubygem-omniauth-azure-oauth2>=0.0.9<0.1.0:net/rubygem-omniauth-azure-oauth2 \
	rubygem-omniauth-cas3>=1.1.4<1.2.0:security/rubygem-omniauth-cas3 \
	rubygem-omniauth-dingtalk-oauth2>=1.0<2:security/rubygem-omniauth-dingtalk-oauth2 \
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
	rubygem-gitlab-omniauth-openid-connect>=0.9.1<0.10.0:net/rubygem-gitlab-omniauth-openid-connect \
	rubygem-omniauth-ultraauth>=0.0.2<0.1.0:net/rubygem-omniauth-ultraauth \
	rubygem-omniauth-salesforce>=1.0.5<1.1.0:net/rubygem-omniauth-salesforce \
	rubygem-omniauth-atlassian-oauth2>=0.2.0<0.3:security/rubygem-omniauth-atlassian-oauth2 \
	rubygem-rack-oauth2>=1.16.0<1.17.0:security/rubygem-rack-oauth2 \
	rubygem-jwt21>=2.1.0<2.2.0:www/rubygem-jwt21 \
	rubygem-gssapi>0:security/rubygem-gssapi \
	rubygem-recaptcha>=4.11<5.0:devel/rubygem-recaptcha \
	rubygem-akismet>=3.0<4.0:devel/rubygem-akismet \
	rubygem-invisible_captcha>=1.1.0<1.2.0:graphics/rubygem-invisible_captcha \
	rubygem-devise-two-factor-rails61>=4.0.0<4.1:security/rubygem-devise-two-factor-rails61 \
	rubygem-rqrcode-rails3>=0.1.7<0.2.0:www/rubygem-rqrcode-rails3 \
	rubygem-attr_encrypted>=3.1.0<3.2.0:security/rubygem-attr_encrypted \
	rubygem-u2f0>=0.2.1<0.3.0:net/rubygem-u2f0 \
	rubygem-validates_hostname>=1.0.11<1.1.0:dns/rubygem-validates_hostname \
	rubygem-rubyzip20>=2.0.0<2.1.0:archivers/rubygem-rubyzip20 \
	rubygem-acme-client>=2.0.9<3:security/rubygem-acme-client \
	rubygem-browser>=4.2<5.0:www/rubygem-browser \
	rubygem-ohai>=16.10<17:sysutils/rubygem-ohai \
	rubygem-gpgme>=2.0.20<2.1.0:security/rubygem-gpgme \
	rubygem-gitlab_omniauth-ldap>=2.1.1<2.2.0:net/rubygem-gitlab_omniauth-ldap \
	rubygem-net-ldap>0.16.3:net/rubygem-net-ldap \
	rubygem-grape15>=1.5.2<1.6:devel/rubygem-grape15 \
	rubygem-grape-entity>=0.10.0<0.11.0,1:devel/rubygem-grape-entity \
	rubygem-rack-cors>=1.0.6<1.1.0:www/rubygem-rack-cors \
	rubygem-graphql>=1.11.10<1.12:devel/rubygem-graphql \
	rubygem-graphiql-rails>=1.8<2:devel/rubygem-graphiql-rails \
	rubygem-apollo_upload_server>=2.1.0<2.2:net/rubygem-apollo_upload_server \
	rubygem-graphql-docs>=1.6.0<1.7.0:devel/rubygem-graphql-docs \
	rubygem-graphlient>=0.4.0<0.5:devel/rubygem-graphlient \
	rubygem-hashie>=4.1.0:devel/rubygem-hashie \
	rubygem-hashie-forbidden_attributes>0:devel/rubygem-hashie-forbidden_attributes \
	rubygem-kaminari-rails61>=1.2.1<2.0:www/rubygem-kaminari-rails61 \
	rubygem-hamlit>=2.15.0<2.16:www/rubygem-hamlit \
	rubygem-carrierwave>=1.3.2<2.0:www/rubygem-carrierwave \
	rubygem-mini_magick410>=4.10.1<4.11:graphics/rubygem-mini_magick410 \
	rubygem-fog-aws>=3.12<4:net/rubygem-fog-aws \
	rubygem-fog-core210=2.1.0:devel/rubygem-fog-core210 \
	rubygem-fog-google>=1.15<2:net/rubygem-fog-google \
	rubygem-fog-local>=0.6<1.0:net/rubygem-fog-local \
	rubygem-fog-openstack>=1.0<2.0:net/rubygem-fog-openstack \
	rubygem-fog-rackspace>=0.1.1<1.2.0:net/rubygem-fog-rackspace \
	rubygem-fog-aliyun>=0.3<1.0:net/rubygem-fog-aliyun \
	rubygem-gitlab-fog-azure-rm>=1.2.0<1.3:net/rubygem-gitlab-fog-azure-rm \
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
	rubygem-typhoeus>=1.4.0<1.5:www/rubygem-typhoeus \
	rubygem-html-pipeline>=2.13.2<2.14:textproc/rubygem-html-pipeline \
	rubygem-deckar01-task_list=2.3.1:www/rubygem-deckar01-task_list \
	rubygem-gitlab-markup>=1.8.0<1.9.0:textproc/rubygem-gitlab-markup \
	rubygem-github-markup17>=1.7.0<1.8.0:textproc/rubygem-github-markup17 \
	rubygem-commonmarker>=0.23.2<0.24:textproc/rubygem-commonmarker \
	rubygem-kramdown>=2.3.1<2.4:textproc/rubygem-kramdown \
	rubygem-redcloth>=4.3.2<4.4.0:www/rubygem-redcloth \
	rubygem-rdoc63>=6.3.2<7:devel/rubygem-rdoc63 \
	rubygem-org-ruby>=0.9.12<0.10.0:textproc/rubygem-org-ruby \
	rubygem-creole>=0.5.0<0.6.0:textproc/rubygem-creole \
	rubygem-wikicloth081>=0.8.1<0.8.2:textproc/rubygem-wikicloth081 \
	rubygem-asciidoctor>=2.0.15<2.1.0:textproc/rubygem-asciidoctor \
	rubygem-asciidoctor-include-ext>=0.3.1<0.4.0:textproc/rubygem-asciidoctor-include-ext \
	rubygem-asciidoctor-plantuml>=0.0.12<0.1:textproc/rubygem-asciidoctor-plantuml \
	rubygem-asciidoctor-kroki>=0.5.0<0.6:textproc/rubygem-asciidoctor-kroki \
	rubygem-rouge>=3.27.0<3.28:textproc/rubygem-rouge \
	rubygem-truncato>=0.7.11<0.8.0:textproc/rubygem-truncato \
	rubygem-bootstrap_form>=4.2.0<4.3.0:devel/rubygem-bootstrap_form \
	rubygem-nokogiri>=1.12<2:textproc/rubygem-nokogiri \
	rubygem-escape_utils>=1.1<2.0:textproc/rubygem-escape_utils \
	rubygem-icalendar>=0:devel/rubygem-icalendar \
	rubygem-diffy>=3.3<4:textproc/rubygem-diffy \
	rubygem-diff_match_patch>=0.1.0<0.2.0:textproc/rubygem-diff_match_patch \
	rubygem-rack>=2.2.3<2.3,3:www/rubygem-rack \
	rubygem-rack-timeout>=0.5.1<0.6:www/rubygem-rack-timeout \
	rubygem-puma>=5.5.2<5.6:www/rubygem-puma \
	rubygem-puma_worker_killer>=0.3.1:www/rubygem-puma_worker_killer \
	rubygem-sd_notify>=0.1.0<0.2:devel/rubygem-sd_notify \
	rubygem-state_machines-activerecord>=0.8.0<0.9.0:databases/rubygem-state_machines-activerecord \
	rubygem-acts-as-taggable-on>=9.0<10:www/rubygem-acts-as-taggable-on \
	rubygem-sidekiq>=6.3<7:devel/rubygem-sidekiq \
	rubygem-sidekiq-cron>=1.2<2.0:devel/rubygem-sidekiq-cron \
	rubygem-redis-namespace>=1.8.1<1.9.0:databases/rubygem-redis-namespace \
	rubygem-gitlab-sidekiq-fetcher>=0.8.0<0.9:devel/rubygem-gitlab-sidekiq-fetcher \
	rubygem-fugit12>=1.2.1<1.3.0:devel/rubygem-fugit12 \
	rubygem-httparty>=0.16.4<0.17.0:www/rubygem-httparty \
	rubygem-rainbow>=3.0<4.0:devel/rubygem-rainbow \
	rubygem-ruby-progressbar>=1.11<2:devel/rubygem-ruby-progressbar \
	rubygem-settingslogic>=2.0.9<2.1.0:devel/rubygem-settingslogic \
	rubygem-re2>=1.2.0<1.3.0:devel/rubygem-re2 \
	rubygem-version_sorter>=2.2.4<2.3.0:textproc/rubygem-version_sorter \
	rubygem-js_regex>=3.7<4.0:textproc/rubygem-js_regex \
	rubygem-device_detector>=0:devel/rubygem-device_detector \
	rubygem-redis44>=4.4.0<4.5:databases/rubygem-redis44 \
	rubygem-connection_pool>=2.0<3.0:net/rubygem-connection_pool \
	rubygem-redis-actionpack-rails61>=5.2.0<5.3:databases/rubygem-redis-actionpack-rails61 \
	rubygem-discordrb-webhooks>=3.4<4.0:net-im/rubygem-discordrb-webhooks \
	rubygem-jira-ruby>=2.1.4<2.2:devel/rubygem-jira-ruby \
	rubygem-atlassian-jwt>=0.2.0<0.3.0:www/rubygem-atlassian-jwt \
	rubygem-flowdock>=0.7<1.0:www/rubygem-flowdock \
	rubygem-slack-messenger>=2.3.4<2.4.0:devel/rubygem-slack-messenger \
	rubygem-hangouts-chat>=0.0.5<0.1.0:net/rubygem-hangouts-chat \
	rubygem-asana>=0.10.3<0.11:www/rubygem-asana \
	rubygem-ruby-fogbugz021>=0.2.1<0.3.0:devel/rubygem-ruby-fogbugz021 \
	rubygem-kubeclient>=4.9.2<4.10.0:www/rubygem-kubeclient \
	rubygem-sanitize>=6.0<7:textproc/rubygem-sanitize \
	rubygem-babosa>=1.0.4<1.1.0:textproc/rubygem-babosa \
	rubygem-loofah>=2.9.0<3.0:textproc/rubygem-loofah \
	rubygem-licensee>=9.14.1<9.15:devel/rubygem-licensee \
	rubygem-charlock_holmes>=0.7.7<0.8.0:textproc/rubygem-charlock_holmes \
	rubygem-ruby-magic>=0.5.4<1:devel/rubygem-ruby-magic \
	rubygem-fast_blank>=0:devel/rubygem-fast_blank \
	rubygem-gitlab-chronic>=0.10.5<0.11.0:devel/rubygem-gitlab-chronic \
	rubygem-gitlab_chronic_duration>=0.10.6.2<0.10.7:devel/rubygem-gitlab_chronic_duration \
	rubygem-rack-proxy06>=0.6.0<0.7.0:www/rubygem-rack-proxy06 \
	rubygem-sassc-rails-rails61>=2.1.0<2.2.0:textproc/rubygem-sassc-rails-rails61 \
	rubygem-autoprefixer-rails1025>=10.2.5.1<10.2.6:textproc/rubygem-autoprefixer-rails1025 \
	rubygem-terser>=1.0.2:textproc/rubygem-terser \
	rubygem-addressable>=2.8<3:www/rubygem-addressable \
	rubygem-tanuki_emoji>=0.5<1:graphics/rubygem-tanuki_emoji \
	rubygem-gon-rails61>=6.4.0<6.5:www/rubygem-gon-rails61 \
	rubygem-request_store>=1.5<2.0:devel/rubygem-request_store \
	rubygem-base32>=0.3.0<0.4.0:converters/rubygem-base32 \
	rubygem-gitlab-license>=2.0<3:devel/rubygem-gitlab-license \
	rubygem-rack-attack>=6.3.0<6.4.0:www/rubygem-rack-attack \
	rubygem-sentry-raven>=3.1<4.0:devel/rubygem-sentry-raven \
	rubygem-pg_query>=2.1<3:databases/rubygem-pg_query \
	rubygem-premailer-rails-rails61>=1.10.3<1.11.0:mail/rubygem-premailer-rails-rails61 \
	rubygem-gitlab-labkit>=0.21.3<0.22:devel/rubygem-gitlab-labkit \
	rubygem-thrift>=0.14.0:devel/rubygem-thrift \
	rubygem-ruby_parser>=3.15<4.0:devel/rubygem-ruby_parser \
	rubygem-rails-i18n-rails61>=6.0<7.0:devel/rubygem-rails-i18n-rails61 \
	rubygem-gettext_i18n_rails>=1.8.0<1.9.0:devel/rubygem-gettext_i18n_rails \
	rubygem-gettext_i18n_rails_js-rails61>=1.3<2.0:devel/rubygem-gettext_i18n_rails_js-rails61 \
	rubygem-gettext>=3.3<4:devel/rubygem-gettext \
	rubygem-batch-loader>=2.0.1<2.1:devel/rubygem-batch-loader \
	rubygem-peek-rails61>=1.1.0<2.0:devel/rubygem-peek-rails61 \
	rubygem-snowplow-tracker>=0.6.1<1:devel/rubygem-snowplow-tracker \
	rubygem-method_source>=1.0<2:devel/rubygem-method_source \
	rubygem-webrick>=1.6.1:www/rubygem-webrick \
	rubygem-prometheus-client-mmap>=0.15.0<0.16.0:devel/rubygem-prometheus-client-mmap \
	rubygem-warning>=1.2.0<1.3:devel/rubygem-warning \
	rubygem-gitlab-license_finder>=6.14.2.1<7:devel/rubygem-gitlab-license_finder \
	rubygem-octokit>=4.20<5.0:net/rubygem-octokit \
	rubygem-gitlab-mail_room>=0.0.9<0.1.0:mail/rubygem-gitlab-mail_room \
	rubygem-email_reply_trimmer>=0.1<1.0:mail/rubygem-email_reply_trimmer \
	rubygem-html2text>=0:textproc/rubygem-html2text \
	rubygem-ruby-prof>=1.3.0<1.4.0:devel/rubygem-ruby-prof \
	rubygem-stackprof>=0.2.15<0.3:devel/rubygem-stackprof \
	rubygem-rbtrace>=0.4.14<1.0:devel/rubygem-rbtrace \
	rubygem-memory_profiler>=0.9<1.0:devel/rubygem-memory_profiler \
	rubygem-benchmark-memory>=0.1<1.0:benchmarks/rubygem-benchmark-memory \
	rubygem-activerecord-explain-analyze>=0.1<1.0:databases/rubygem-activerecord-explain-analyze \
	rubygem-oauth2>=1.4.7<2.0:net/rubygem-oauth2 \
	rubygem-health_check>=3.0<4:devel/rubygem-health_check \
	rubygem-vmstat>=2.3.0<2.4.0:sysutils/rubygem-vmstat \
	rubygem-sys-filesystem>=1.4.3<1.5:sysutils/rubygem-sys-filesystem \
	rubygem-net-ntp>0:net/rubygem-net-ntp \
	rubygem-net-ssh>=6.0<7,2:security/rubygem-net-ssh \
	rubygem-sshkey>=2.0<3.0:security/rubygem-sshkey \
	rubygem-ed25519>=1.2<2.0:security/rubygem-ed25519 \
	rubygem-bcrypt_pbkdf>=1.1<2.0:security/rubygem-bcrypt_pbkdf \
	rubygem-spamcheck>=0.1.0<0.2:net/rubygem-spamcheck \
	rubygem-gitaly>=14.6.0.pre.rc1<14.7.0:net/rubygem-gitaly \
	rubygem-kas-grpc>=0.0.2,1<0.0.3,1:net/rubygem-kas-grpc \
	rubygem-grpc142>=1.42.0<1.43:net/rubygem-grpc142 \
	rubygem-google-protobuf>=3.19.0<3.20:devel/rubygem-google-protobuf \
	rubygem-toml-rb>=2.0.1<3:www/rubygem-toml-rb \
	rubygem-flipper021>=0.21.0<0.22:devel/rubygem-flipper021 \
	rubygem-flipper-active_record-rails61>=0.21.0<0.22:databases/rubygem-flipper-active_record-rails61 \
	rubygem-flipper-active_support_cache_store-rails61>=0.21.0<0.22:devel/rubygem-flipper-active_support_cache_store-rails61 \
	rubygem-unleash>=3.2.2<3.3:devel/rubygem-unleash \
	rubygem-gitlab-experiment>=0.6.5<0.7:devel/rubygem-gitlab-experiment \
	rubygem-lograge-rails61>=0.11.2<1.0:www/rubygem-lograge-rails61 \
	rubygem-grape_logging>=1.7<2.0:devel/rubygem-grape_logging \
	rubygem-gitlab-net-dns>=0.9.1<0.10:dns/rubygem-gitlab-net-dns \
	rubygem-countries>=3.0.0<4.0.0:devel/rubygem-countries \
	rubygem-retriable>=3.1.2<3.2.0:devel/rubygem-retriable \
	rubygem-lru_redux>0:devel/rubygem-lru_redux \
	rubygem-erubi19>=1.9.0<1.10:www/rubygem-erubi19 \
	rubygem-mail>=2.7.1<2.7.2,2:mail/rubygem-mail \
	rubygem-lockbox>=0.6.2<0.7:security/rubygem-lockbox \
	rubygem-valid_email>=0.1<1:mail/rubygem-valid_email \
	rubygem-json>=2.5.1<2.6:devel/rubygem-json \
	rubygem-json_schemer>=0.2.18<0.3:devel/rubygem-json_schemer \
	rubygem-oj310>=3.10.6<3.11:devel/rubygem-oj310 \
	rubygem-multi_json114>=1.14.1<1.15:devel/rubygem-multi_json114 \
	rubygem-yajl-ruby>=1.4.1<1.5:devel/rubygem-yajl-ruby \
	rubygem-webauthn>=2.3<3:security/rubygem-webauthn \
	rubygem-ipaddress>=0.8.3<0.9:net/rubygem-ipaddress \
	rubygem-parslet1>=1.8<2:textproc/rubygem-parslet1 \
	rubygem-ipynbdiff>=0.3.8<0.3.9:devel/rubygem-ipynbdiff \
	rubygem-parser>=0:devel/rubygem-parser

BUILD_DEPENDS=	gem:devel/ruby-gems \
	${MY_DEPENDS}

RUN_DEPENDS=	${MY_DEPENDS}

CONFLICTS_INSTALL=	gitolite \
			gitolite2 \
			gogs \
			gitea \
			gitosis

USES=		go:modules shebangfix
USE_RUBY=	yes

USE_RC_SUBR=	gitlab
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GL_PROJECT=	gitlab-foss
# Find the here: https://gitlab.com/gitlab-org/gitlab-foss/-/tags
GL_COMMIT=	293f6bb322ba6f3aba63744cea1cc3c9d648aba0

USERS=	git
GROUPS=	git

NO_BUILD=	yes

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config/gitlab.yml.example \
		${WRKSRC}/config/puma.rb.example \
		${WRKSRC}/lib/support/nginx/gitlab \
		${WRKSRC}/lib/support/nginx/gitlab-ssl
	# Remove symlink a create a file with content
	${RM} ${WRKSRC}/GITLAB_WORKHORSE_VERSION
	${ECHO} ${PORTVERSION} > ${WRKSRC}/GITLAB_WORKHORSE_VERSION

do-install:
	${CP} ${WRKSRC}/config/database.yml.postgresql ${WRKSRC}/config/database.yml.sample
	(cd ${WRKSRC} && ${RM} Gemfile.lock && bundle install --local)
	${RM} -R ${WRKSRC}/workhorse
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete
	${FIND} ${WRKSRC} -name '*.gitkeep' -delete
	${FIND} ${WRKSRC} -name '*.gitignore' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	${MV} ${WRKSRC}/config/initializers/relative_url.rb.sample ${WRKSRC}/config/initializers/relative_url.rb.example
	# get files for workdir with: find . -name "*.example"
	${MV} ${WRKSRC}/config/puma.rb.example ${WRKSRC}/config/puma.rb.sample
	${MV} ${WRKSRC}/config/secrets.yml.example ${WRKSRC}/config/secrets.yml.sample
	${MV} ${WRKSRC}/config/sidekiq.yml.example ${WRKSRC}/config/sidekiq.yml.sample
	${MV} ${WRKSRC}/config/cable.yml.example ${WRKSRC}/config/cable.yml.sample
	${MV} ${WRKSRC}/config/gitlab.yml.example ${WRKSRC}/config/gitlab.yml.sample
	${MV} ${WRKSRC}/config/initializers/devise_password_length.rb.example ${WRKSRC}/config/initializers/devise_password_length.rb.sample
	${MV} ${WRKSRC}/config/resque.yml.example ${WRKSRC}/config/resque.yml.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab ${WRKSRC}/lib/support/nginx/gitlab.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab-ssl ${WRKSRC}/lib/support/nginx/gitlab-ssl.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/assets
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/uploads
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/cache
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/sessions
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/backups
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/sockets/private/internal
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/tmp
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/shared/artifacts/tmp/work
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/vendor/assets/stylesheets
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/workhorse/changelogs/unreleased
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		/secrets.yml.sample$$/ s#^@sample #@sample(git,www,0600) #; \
		s#${WWWDIR_REL}/bin#@(git,,544) ${WWWDIR_REL}/bin#; \
		/db\/schema.rb$$|gitlab.po$$|gitlab.pot$$|gitlab.po.time_stamp$$|locale\/index.js$$/ s#^#@(git,,) #;' >> ${TMPPLIST}
	@${ECHO_CMD} "@owner git" >> ${TMPPLIST}
	@${ECHO_CMD} "@group www" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(git,git) ${WWWDIR_REL}/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/app/assets/images/auth_buttons/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/app/assets/javascripts/locale/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(git,git,554) ${WWWDIR_REL}/bin" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/config" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/builds" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/lib/assets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/bg" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/de" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/eo" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/es" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/fil_PH" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/fr" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/id_ID" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/it" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/ja" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/ko" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/nl_NL" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/pl_PL" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/pt_BR" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/ru" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/tr_TR" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/uk" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/zh_CN" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/zh_HK" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/locale/zh_TW" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/log" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/public" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/public/assets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/public/uploads" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/api/2_plan" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/api/4_verify" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/api/5_package" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/api/6_release" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/api/7_configure" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/api/8_monitor" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/browser_ui/5_package" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/browser_ui/8_monitor" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/spec/support/gitlab-git-test.git/refs/heads" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/spec/support/gitlab-git-test.git/refs/tags" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts/tmp" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts/tmp/cache" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts/tmp/uploads" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts/tmp/work" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/shared/packages" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/shared/pages" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/terraform_state" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/tmp" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/lfs-objects" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/registry" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/backups" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/cache" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/feature_flags" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/pids" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/prometheus_multiproc_dir" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/prometheus_multiproc_dir/puma" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/prometheus_multiproc_dir/sidekiq" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/prometheus_multiproc_dir/unicorn" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sessions" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sockets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sockets/private" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sockets/private/internal" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/vendor" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/vendor/assets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/vendor/assets/stylesheets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/workhorse/changelogs/unreleased" >> ${TMPPLIST}

.include <bsd.port.mk>
