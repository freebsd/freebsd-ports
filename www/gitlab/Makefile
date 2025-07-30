PORTNAME=	gitlab-${FLAVOR:Uce}
PORTVERSION=	${GITLAB_VERSION}
DISTVERSIONPREFIX=	v
.if ${FLAVOR:U} == ee
DISTVERSIONSUFFIX=	-ee
.endif
PORTREVISION=	${GITLAB_PORTREVISION} # modify it in www/gitlab/Makefile.common
CATEGORIES=	www devel

# include patch to fix database migration
#https://gitlab.com/gitlab-org/gitlab/-/merge_requests/153560.patch
#PATCH_SITES=	https://gitlab.com/gitlab-org/gitlab/-/merge_requests/
#PATCHFILES+=	153560.patch:-p1 # https://gitlab.com/gitlab-org/gitlab/-/merge_requests/153560

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Web GUI for managing git repositories
WWW=		https://gitlab.com/ \
		https://gitlab.com/gitlab-org/gitlab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# the rubygems of RUN_DEPENDS matches the order of the Gemfile
# which makes maintaining this long list much easier!
# devel/rubygem-parser is required for database upgrade process
# see https://gitlab.com/gitlab-org/gitlab/-/issues/350866
# mail/rubygem-net-smtp is required as ruby 3.1 removed it
# textproc/rubygem-psych3 is required as ruby 3.1 applied an update to psych 4.0 which has breaking changes
# mail/rubygem-net-pop is required as ruby 3.1 removed it
#gitlab-zoekt-indexer>=0.16.0:textproc/gitlab-zoekt-indexer
MY_DEPENDS=	gitaly>=${GITLAB_VERSION}:devel/gitaly \
	gitlab-elasticsearch-indexer>=5.7.0:textproc/gitlab-elasticsearch-indexer \
	gitlab-agent>=${GITLAB_VERSION}:net/gitlab-agent \
	gitlab-pages>=${GITLAB_VERSION}:www/gitlab-pages \
	gitlab-shell>=14.43.0:devel/gitlab-shell \
	gitlab-workhorse>=${GITLAB_VERSION}:www/gitlab-workhorse \
	gitlab-zoekt-indexer>=0.24.0:textproc/gitlab-zoekt-indexer \
	redis>=6.2.11:databases/redis \
	yarn${NODEJS_SUFFIX}>=1.10.0:www/yarn${NODEJS_SUFFIX} \
	gtar>0:archivers/gtar \
	bash>0:shells/bash \
	rubygem-parser>=3.3.7.1:devel/rubygem-parser \
	rubygem-net-smtp>=0:mail/rubygem-net-smtp \
	rubygem-psych3>=3.1<4:textproc/rubygem-psych3 \
	rubygem-net-pop>=0:mail/rubygem-net-pop \
	rubygem-rails-gitlab>=7.1.5.1<7.2:www/rubygem-rails-gitlab \
	rubygem-mutex_m>=0.3<1:devel/rubygem-mutex_m \
	rubygem-drb-gitlab>=2.2.3<3:devel/rubygem-drb-gitlab \
	rubygem-bootsnap>=1.18.6<1.19:devel/rubygem-bootsnap \
	rubygem-ffi>=1.17.2<2:devel/rubygem-ffi \
	rubygem-openssl>=3.3.0<4:security/rubygem-openssl \
	rubygem-gitlab-secret_detection>=0.33.0<1:security/rubygem-gitlab-secret_detection \
	rubygem-responders-rails-gitlab>=3.0<4.0:www/rubygem-responders-rails-gitlab \
	rubygem-sprockets-gitlab>=3.7.5<3.8:devel/rubygem-sprockets-gitlab \
	rubygem-sprockets-rails-rails-gitlab>=3.5.2<3.6:devel/rubygem-sprockets-rails-rails-gitlab \
	rubygem-view_component-rails-gitlab>=3.23.2<3.24:devel/rubygem-view_component-rails-gitlab \
	rubygem-pg>=1.5.9<1.6:databases/rubygem-pg \
	rubygem-rugged>=1.6<2:devel/rubygem-rugged \
	rubygem-faraday-gitlab>=2.13.1<3:www/rubygem-faraday-gitlab \
	rubygem-faraday-retry-gitlab>=2<3:www/rubygem-faraday-retry-gitlab \
	rubygem-logger-gitlab>=1.7.0<1.8:devel/rubygem-logger-gitlab \
	rubygem-marginalia>=1.11.1<1.12:databases/rubygem-marginalia \
	rubygem-declarative_policy>=1.1.0<1.2:security/rubygem-declarative_policy \
	rubygem-coverband>=6.1.5<6.1.6:www/rubygem-coverband \
	rubygem-devise-rails-gitlab>=4.9.3<4.10:devel/rubygem-devise-rails-gitlab \
	rubygem-bcrypt>=3.1.20<3.2:security/rubygem-bcrypt \
	rubygem-doorkeeper-rails-gitlab>=5.8.1<6:security/rubygem-doorkeeper-rails-gitlab \
	rubygem-doorkeeper-openid_connect>=1.8.11<2:security/rubygem-doorkeeper-openid_connect \
	rubygem-doorkeeper-device_authorization_grant>=1.0.0<1.1:security/rubygem-doorkeeper-device_authorization_grant \
	rubygem-rexml>=3.4.1<3.5:textproc/rubygem-rexml \
	rubygem-ruby-saml-gitlab>=1.18<2:security/rubygem-ruby-saml-gitlab \
	rubygem-omniauth-saml-gitlab>=2.2.3<3:security/rubygem-omniauth-saml-gitlab \
	rubygem-omniauth>=2.1.3<3:security/rubygem-omniauth \
	rubygem-omniauth-auth0-gitlab>=3.1.1<3.2.0:net/rubygem-omniauth-auth0-gitlab \
	rubygem-omniauth-azure-activedirectory-v2>=2.0<3:net/rubygem-omniauth-azure-activedirectory-v2 \
	rubygem-omniauth-alicloud>=3.0.0<3.1:security/rubygem-omniauth-alicloud \
	rubygem-omniauth-github-gitlab>=2.0.1<2.1:net/rubygem-omniauth-github-gitlab \
	rubygem-omniauth-google-oauth2-gitlab>=1.1<2:net/rubygem-omniauth-google-oauth2-gitlab \
	rubygem-omniauth-oauth2-generic-gitlab>=0.2.2<0.3.0:security/rubygem-omniauth-oauth2-generic-gitlab \
	rubygem-omniauth-shibboleth-redux>=2.0<3:security/rubygem-omniauth-shibboleth-redux \
	rubygem-omniauth_openid_connect>=0.8.0<0.9:net/rubygem-omniauth_openid_connect \
	rubygem-openid_connect>=2.3.1<2.4:net/rubygem-openid_connect \
	rubygem-omniauth-atlassian-oauth2>=0.2.0<0.3:security/rubygem-omniauth-atlassian-oauth2 \
	rubygem-rack-oauth2-gitlab>=2.2.1<2.3:security/rubygem-rack-oauth2-gitlab \
	rubygem-jwt29>=2.9.3<3:www/rubygem-jwt29 \
	rubygem-gssapi>=1.3.1<1.4:security/rubygem-gssapi \
	rubygem-recaptcha>=5.12<6.0:devel/rubygem-recaptcha \
	rubygem-akismet>=3.0<4.0:devel/rubygem-akismet \
	rubygem-invisible_captcha>=2.1.0<2.2.0:graphics/rubygem-invisible_captcha \
	rubygem-devise-two-factor-rails-gitlab>=4.1.1<4.2:security/rubygem-devise-two-factor-rails-gitlab \
	rubygem-rqrcode-gitlab>=2.2.0<3:www/rubygem-rqrcode-gitlab \
	rubygem-attr_encrypted>=4.2<5:security/rubygem-attr_encrypted \
	rubygem-validates_hostname-gitlab>=1.0.13<1.1.0:dns/rubygem-validates_hostname-gitlab \
	rubygem-rubyzip-gitlab>=2.4.1<2.5:archivers/rubygem-rubyzip-gitlab \
	rubygem-acme-client-gitlab>=2.0.22<3:security/rubygem-acme-client-gitlab \
	rubygem-browser5>=5.3.1<5.4:www/rubygem-browser5 \
	rubygem-ohai>=18.1.18<19:sysutils/rubygem-ohai \
	rubygem-gpgme>=2.0.24<2.1.0:security/rubygem-gpgme \
	rubygem-gitlab_omniauth-ldap>=2.2.0<2.3.0:net/rubygem-gitlab_omniauth-ldap \
	rubygem-net-ldap017>=0.17.1<0.18:net/rubygem-net-ldap017 \
	rubygem-grape20>=2.0.0<2.1:devel/rubygem-grape20 \
	rubygem-grape-entity>=1.0.1<1.1,1:devel/rubygem-grape-entity \
	rubygem-grape-swagger>=2.1.2<2.2:devel/rubygem-grape-swagger \
	rubygem-grape-swagger-entity>=0.5.5<0.6:devel/rubygem-grape-swagger-entity \
	rubygem-grape-path-helpers>=2.0.1<2.1:devel/rubygem-grape-path-helpers \
	rubygem-rack-cors>=2.0.1<2.1:www/rubygem-rack-cors \
	rubygem-graphql>=2.4.13<2.5:devel/rubygem-graphql \
	rubygem-apollo_upload_server>=2.1.6<2.2:net/rubygem-apollo_upload_server \
	rubygem-ffaker>=2.24.0<3:devel/rubygem-ffaker \
	rubygem-hashie>=5.0.0<5.1:devel/rubygem-hashie \
	rubygem-kaminari-rails-gitlab>=1.2.2<1.3:www/rubygem-kaminari-rails-gitlab \
	rubygem-hamlit>=2.15.0<2.16:www/rubygem-hamlit \
	rubygem-carrierwave-gitlab>=1.3.4<2.0:www/rubygem-carrierwave-gitlab \
	rubygem-mini_magick4>=4.12<5:graphics/rubygem-mini_magick4 \
	rubygem-prawn>=0:print/rubygem-prawn \
	rubygem-prawn-svg>=0:print/rubygem-prawn-svg \
	rubygem-fog-aws-gitlab>=3.26<4:net/rubygem-fog-aws-gitlab \
	rubygem-fog-core-gitlab>=2.1.0<2.1.1:devel/rubygem-fog-core-gitlab \
	rubygem-fog-google-gitlab>=1.24.1<1.25:net/rubygem-fog-google-gitlab \
	rubygem-fog-local-gitlab>=0.8<1.0:net/rubygem-fog-local-gitlab \
	rubygem-fog-aliyun-gitlab>=0.4<1.0:net/rubygem-fog-aliyun-gitlab \
	rubygem-gitlab-fog-azure-rm>=2.2.0<2.3:net/rubygem-gitlab-fog-azure-rm \
	rubygem-google-apis-storage_v1-gitlab>=0.29<1:devel/rubygem-google-apis-storage_v1-gitlab \
	rubygem-google-cloud-storage-gitlab>=1.45.0<1.46:net/rubygem-google-cloud-storage-gitlab \
	rubygem-google-apis-core-gitlab>=0.11.2<2:devel/rubygem-google-apis-core-gitlab \
	rubygem-google-apis-compute_v1-gitlab>=0.57.0<0.58:devel/rubygem-google-apis-compute_v1-gitlab \
	rubygem-google-apis-container_v1>=0.43.0<0.44:devel/rubygem-google-apis-container_v1 \
	rubygem-google-apis-container_v1beta1>=0.43.0<0.44:devel/rubygem-google-apis-container_v1beta1 \
	rubygem-google-apis-cloudbilling_v1>=0.22.0<0.23:devel/rubygem-google-apis-cloudbilling_v1 \
	rubygem-google-apis-cloudresourcemanager_v1-gitlab>=0.31.0<0.32:devel/rubygem-google-apis-cloudresourcemanager_v1-gitlab \
	rubygem-google-apis-iam_v1-gitlab>=0.36.0<0.37:devel/rubygem-google-apis-iam_v1-gitlab \
	rubygem-google-apis-serviceusage_v1>=0.28.0<0.29:devel/rubygem-google-apis-serviceusage_v1 \
	rubygem-google-apis-sqladmin_v1beta4-gitlab>=0.41.0<0.42:devel/rubygem-google-apis-sqladmin_v1beta4-gitlab \
	rubygem-google-apis-androidpublisher_v3-gitlab>=0.34.0<0.35:devel/rubygem-google-apis-androidpublisher_v3-gitlab \
	rubygem-googleauth-gitlab>=1.8.1<2:security/rubygem-googleauth-gitlab \
	rubygem-google-cloud-artifact_registry-v1>=0.11.0<0.12:textproc/rubygem-google-cloud-artifact_registry-v1 \
	rubygem-google-cloud-compute-v1>=2.6.0<2.7:net/rubygem-google-cloud-compute-v1 \
	rubygem-seed-fu-gitlab>=2.3.9<2.4.0:databases/rubygem-seed-fu-gitlab \
	rubygem-elasticsearch-model-gitlab>=7.2<8:textproc/rubygem-elasticsearch-model-gitlab \
	rubygem-elasticsearch-rails7>=7.2<8:textproc/rubygem-elasticsearch-rails7 \
	rubygem-elasticsearch-api-gitlab>=7.17.11<7.18:textproc/rubygem-elasticsearch-api-gitlab \
	rubygem-aws-sdk-core-gitlab>=3.225.0<3.226:devel/rubygem-aws-sdk-core-gitlab \
	rubygem-aws-sdk-cloudformation-gitlab>=1.133<2:devel/rubygem-aws-sdk-cloudformation-gitlab \
	rubygem-aws-sdk-s3-gitlab>=1.189.0<1.190:devel/rubygem-aws-sdk-s3-gitlab \
	rubygem-faraday-typhoeus-gitlab>=1.1<2:www/rubygem-faraday-typhoeus-gitlab \
	rubygem-faraday_middleware-aws-sigv4-gitlab>=1.0.1<1.1:devel/rubygem-faraday_middleware-aws-sigv4-gitlab \
	rubygem-typhoeus>=1.4.0<1.5:www/rubygem-typhoeus \
	rubygem-html-pipeline-gitlab>=2.14.3<2.15:textproc/rubygem-html-pipeline-gitlab \
	rubygem-deckar01-task_list-gitlab>=2.3.4<2.4:www/rubygem-deckar01-task_list-gitlab \
	rubygem-gitlab-markup>=2.0.0<2.1:textproc/rubygem-gitlab-markup \
	rubygem-commonmarker0>=0.23.10<0.24:textproc/rubygem-commonmarker0 \
	rubygem-kramdown-gitlab>=2.5.1<2.6:textproc/rubygem-kramdown-gitlab \
	rubygem-redcloth>=4.3.3<4.4.0:www/rubygem-redcloth \
	rubygem-org-ruby>=0.9.12<0.10.0:textproc/rubygem-org-ruby \
	rubygem-creole>=0.5.0<0.6.0:textproc/rubygem-creole \
	rubygem-wikicloth081>=0.8.1<0.8.2:textproc/rubygem-wikicloth081 \
	rubygem-asciidoctor>=2.0.18<2.1.0:textproc/rubygem-asciidoctor \
	rubygem-asciidoctor-include-ext>=0.4.0<0.5.0:textproc/rubygem-asciidoctor-include-ext \
	rubygem-asciidoctor-plantuml00>=0.0.16<0.1:textproc/rubygem-asciidoctor-plantuml00 \
	rubygem-asciidoctor-kroki>=0.10.0<0.11:textproc/rubygem-asciidoctor-kroki \
	rubygem-rouge-gitlab>=4.5.2<4.6:textproc/rubygem-rouge-gitlab \
	rubygem-truncato>=0.7.13<0.8.0:textproc/rubygem-truncato \
	rubygem-nokogiri>=1.18.7<2:textproc/rubygem-nokogiri \
	rubygem-gitlab-glfm-markdown>=0.0.31<0.1:textproc/rubygem-gitlab-glfm-markdown \
	rubygem-tanuki_emoji>=0.13<1:graphics/rubygem-tanuki_emoji \
	rubygem-unicode-emoji>=4.0.4<5:devel/rubygem-unicode-emoji \
	rubygem-icalendar-gitlab>=2.10.3<2.11:devel/rubygem-icalendar-gitlab \
	rubygem-diffy>=3.4.4<4:textproc/rubygem-diffy \
	rubygem-rack22>=2.2.17,3<2.3,3:www/rubygem-rack22 \
	rubygem-rack-timeout>=0.7.0<0.8:www/rubygem-rack-timeout \
	rubygem-puma>=6.6.0<6.6.1:www/rubygem-puma \
	rubygem-sd_notify>=0.1.1<0.2:devel/rubygem-sd_notify \
	rubygem-state_machines-activerecord-gitlab>=0.8.0<0.9.0:databases/rubygem-state_machines-activerecord-gitlab \
	rubygem-sidekiq-gitlab>=7.3.9:devel/rubygem-sidekiq-gitlab \
	rubygem-sidekiq-cron-rails-gitlab>=1.12.0<1.13:devel/rubygem-sidekiq-cron-rails-gitlab \
	rubygem-fugit>=1.11.1<1.12:devel/rubygem-fugit \
	rubygem-httparty-gitlab>=0.23.0<0.24:www/rubygem-httparty-gitlab \
	rubygem-rainbow>=3.1.1<4.0:devel/rubygem-rainbow \
	rubygem-ruby-progressbar>=1.11<2:devel/rubygem-ruby-progressbar \
	rubygem-re2>=2.15.0<3:devel/rubygem-re2 \
	rubygem-semver_dialects>=3.7.0<4:devel/rubygem-semver_dialects \
	rubygem-version_sorter>=2.3<3:textproc/rubygem-version_sorter \
	rubygem-js_regex>=3.8<4.0:textproc/rubygem-js_regex \
	rubygem-device_detector>=1.1.3:devel/rubygem-device_detector \
	rubygem-redis>=5.4.0<5.5:databases/rubygem-redis \
	rubygem-redis-clustering>=5.4.0<5.5:databases/rubygem-redis-clustering \
	rubygem-connection_pool>=2.5.3<2.6:net/rubygem-connection_pool \
	rubygem-redis-actionpack-rails-gitlab>=5.5.0<5.6:databases/rubygem-redis-actionpack-rails-gitlab \
	rubygem-jira-ruby-gitlab>=2.3.0<2.4:devel/rubygem-jira-ruby-gitlab \
	rubygem-atlassian-jwt>=0.2.1<0.3.0:www/rubygem-atlassian-jwt \
	rubygem-slack-messenger>=2.3.5<2.4.0:devel/rubygem-slack-messenger \
	rubygem-kubeclient>=4.11.0<4.12.0:www/rubygem-kubeclient \
	rubygem-ruby-openai37>=3.7<4:www/rubygem-ruby-openai37 \
	rubygem-circuitbox>=2.0.0<2.1:www/rubygem-circuitbox \
	rubygem-sanitize60>=6.0.2<6.1:textproc/rubygem-sanitize60 \
	rubygem-babosa>=2.0<3:textproc/rubygem-babosa \
	rubygem-loofah>=2.24.1<2.25:textproc/rubygem-loofah \
	rubygem-licensee-gitlab>=9.16<10:devel/rubygem-licensee-gitlab \
	rubygem-charlock_holmes>=0.7.9<0.8:textproc/rubygem-charlock_holmes \
	rubygem-ruby-magic>=0.6<1:devel/rubygem-ruby-magic \
	rubygem-fast_blank>=1.0.1<1.1:devel/rubygem-fast_blank \
	rubygem-gitlab-chronic>=0.10.6<0.11.0:devel/rubygem-gitlab-chronic \
	rubygem-gitlab_chronic_duration>=0.12<1:devel/rubygem-gitlab_chronic_duration \
	rubygem-rack-proxy>=0.7.7<0.8.0:www/rubygem-rack-proxy \
	rubygem-cssbundling-rails-rails-gitlab>=1.4.3<1.5:www/rubygem-cssbundling-rails-rails-gitlab \
	rubygem-terser>=1.0.2<1.0.3:textproc/rubygem-terser \
	rubygem-addressable>=2.8<3:www/rubygem-addressable \
	rubygem-gon-rails-gitlab>=6.4.0<6.5:www/rubygem-gon-rails-gitlab \
	rubygem-request_store>=1.7.0<1.8:devel/rubygem-request_store \
	rubygem-base32>=0.3.4<0.4.0:converters/rubygem-base32 \
	rubygem-gitlab-license>=2.6<3:devel/rubygem-gitlab-license \
	rubygem-rack-attack>=6.7.0<6.8:www/rubygem-rack-attack \
	rubygem-sentry-ruby>=5.23.0<5.24:devel/rubygem-sentry-ruby \
	rubygem-sentry-rails>=5.23.0<5.24:devel/rubygem-sentry-rails \
	rubygem-sentry-sidekiq>=5.23.0<5.24:devel/rubygem-sentry-sidekiq \
	rubygem-pg_query>=6.1.0<6.2:databases/rubygem-pg_query \
	rubygem-premailer-rails-rails-gitlab>=1.12.0<1.13:mail/rubygem-premailer-rails-rails-gitlab \
	rubygem-gitlab-labkit>=0.39.0<0.40:devel/rubygem-gitlab-labkit \
	rubygem-thrift>=0.16.0:devel/rubygem-thrift \
	rubygem-rails-i18n-rails-gitlab>=7.0.9<8:devel/rubygem-rails-i18n-rails-gitlab \
	rubygem-gettext_i18n_rails>=1.13.0<1.14:devel/rubygem-gettext_i18n_rails \
	rubygem-gettext>=3.5.1<4:devel/rubygem-gettext \
	rubygem-batch-loader>=2.0.5<2.1:devel/rubygem-batch-loader \
	rubygem-tty-prompt>=0.23<1:devel/rubygem-tty-prompt \
	rubygem-peek-rails-gitlab>=1.1<2.0:devel/rubygem-peek-rails-gitlab \
	rubygem-snowplow-tracker>=0.8.0<1:devel/rubygem-snowplow-tracker \
	rubygem-webrick>=1.9.0<1.10:www/rubygem-webrick \
	rubygem-prometheus-client-mmap>=1.2.10<1.3:devel/rubygem-prometheus-client-mmap \
	rubygem-async-gitlab>=2.24.0<2.25:devel/rubygem-async-gitlab \
	rubygem-gitlab-security_report_schemas>=0.1.3.min15.0.0.max15.2.2<0.1.3.min15.0.0.max15.2.3:devel/rubygem-gitlab-security_report_schemas \
	rubygem-opentelemetry-sdk>=1.5.0:devel/rubygem-opentelemetry-sdk \
	rubygem-opentelemetry-exporter-otlp>=0.29.1:devel/rubygem-opentelemetry-exporter-otlp \
	rubygem-opentelemetry-instrumentation-active_support>=0.6.0:devel/rubygem-opentelemetry-instrumentation-active_support \
	rubygem-opentelemetry-instrumentation-action_pack>=0.10.0:devel/rubygem-opentelemetry-instrumentation-action_pack \
	rubygem-opentelemetry-instrumentation-active_job>=0.7.7:devel/rubygem-opentelemetry-instrumentation-active_job \
	rubygem-opentelemetry-instrumentation-active_record>=0.8.1:devel/rubygem-opentelemetry-instrumentation-active_record \
	rubygem-opentelemetry-instrumentation-action_view>=0.7.2:devel/rubygem-opentelemetry-instrumentation-action_view \
	rubygem-opentelemetry-instrumentation-aws_sdk>=0.5.4:devel/rubygem-opentelemetry-instrumentation-aws_sdk \
	rubygem-opentelemetry-instrumentation-http>=0.23.4:devel/rubygem-opentelemetry-instrumentation-http \
	rubygem-opentelemetry-instrumentation-concurrent_ruby>=0.21.4:devel/rubygem-opentelemetry-instrumentation-concurrent_ruby \
	rubygem-opentelemetry-instrumentation-ethon>=0.21.9:devel/rubygem-opentelemetry-instrumentation-ethon \
	rubygem-opentelemetry-instrumentation-excon>=0.22.5:devel/rubygem-opentelemetry-instrumentation-excon \
	rubygem-opentelemetry-instrumentation-faraday>=0.24.7:devel/rubygem-opentelemetry-instrumentation-faraday \
	rubygem-opentelemetry-instrumentation-grape>=0.2.0:devel/rubygem-opentelemetry-instrumentation-grape \
	rubygem-opentelemetry-instrumentation-graphql>=0.28.4:devel/rubygem-opentelemetry-instrumentation-graphql \
	rubygem-opentelemetry-instrumentation-http_client>=0.22.8:devel/rubygem-opentelemetry-instrumentation-http_client \
	rubygem-opentelemetry-instrumentation-net_http>=0.22.8:devel/rubygem-opentelemetry-instrumentation-net_http \
	rubygem-opentelemetry-instrumentation-pg>=0.29.1:devel/rubygem-opentelemetry-instrumentation-pg \
	rubygem-opentelemetry-instrumentation-rack>=0.24.6:devel/rubygem-opentelemetry-instrumentation-rack \
	rubygem-opentelemetry-instrumentation-rails>=0.33.1:devel/rubygem-opentelemetry-instrumentation-rails \
	rubygem-opentelemetry-instrumentation-rake>=0.2.1:devel/rubygem-opentelemetry-instrumentation-rake \
	rubygem-opentelemetry-instrumentation-redis>=0.25.7:devel/rubygem-opentelemetry-instrumentation-redis \
	rubygem-opentelemetry-instrumentation-sidekiq>=0.25.7:devel/rubygem-opentelemetry-instrumentation-sidekiq \
	rubygem-warning>=1.5.0<1.6:devel/rubygem-warning \
	rubygem-git>=1.19.1<2:devel/rubygem-git \
	rubygem-gitlab-dangerfiles>=4.9.2<4.10:devel/rubygem-gitlab-dangerfiles \
	rubygem-license_finder-gitlab>=7.2.1<8:devel/rubygem-license_finder-gitlab \
	rubygem-rspec>=3.0<4:devel/rubygem-rspec \
	rubygem-octokit-gitlab>=9.0<10:net/rubygem-octokit-gitlab \
	rubygem-faraday-multipart>=1.1.1<2:www/rubygem-faraday-multipart \
	rubygem-gitlab-mail_room>=0.0.27<0.1.0:mail/rubygem-gitlab-mail_room \
	rubygem-email_reply_trimmer>=0.1<1.0:mail/rubygem-email_reply_trimmer \
	rubygem-html2text>=0:textproc/rubygem-html2text \
	rubygem-stackprof>=0.2.27<0.3:devel/rubygem-stackprof \
	rubygem-rbtrace>=0.5.2<1.0:devel/rubygem-rbtrace \
	rubygem-memory_profiler>=1.0<2.0:devel/rubygem-memory_profiler \
	rubygem-activerecord-explain-analyze>=0.1<1.0:databases/rubygem-activerecord-explain-analyze \
	rubygem-oauth2-gitlab>=2.0.10<3:net/rubygem-oauth2-gitlab \
	rubygem-health_check-rails-gitlab>=3.0<4:devel/rubygem-health_check-rails-gitlab \
	rubygem-vmstat>=2.3.1<2.4.0:sysutils/rubygem-vmstat \
	rubygem-sys-filesystem14>=1.4.3<1.5:sysutils/rubygem-sys-filesystem14 \
	rubygem-net-ntp>0:net/rubygem-net-ntp \
	rubygem-ssh_data>=1.3<2:security/rubygem-ssh_data \
	rubygem-spamcheck>=1.3.3<1.4:net/rubygem-spamcheck \
	rubygem-gitaly>=18.1.0:net/rubygem-gitaly \
	rubygem-gitlab-kas-grpc>=${GITLAB_KAS_GRPC_VERSION}:net/rubygem-gitlab-kas-grpc \
	rubygem-grpc-gitlab>=1.72.0<2:net/rubygem-grpc-gitlab \
	rubygem-google-protobuf3>=3.25.8<4:devel/rubygem-google-protobuf3 \
	rubygem-toml-rb>=2.2.0<3:www/rubygem-toml-rb \
	rubygem-flipper-gitlab>=0.28.0<0.29:devel/rubygem-flipper-gitlab \
	rubygem-flipper-active_record-rails-gitlab>=0.28.0<0.29:databases/rubygem-flipper-active_record-rails-gitlab \
	rubygem-flipper-active_support_cache_store-rails-gitlab>=0.28.0<0.29:devel/rubygem-flipper-active_support_cache_store-rails-gitlab \
	rubygem-unleash>=3.2.2<3.3:devel/rubygem-unleash \
	rubygem-gitlab-experiment>=0.9.1<0.10:devel/rubygem-gitlab-experiment \
	rubygem-lograge-rails-gitlab>=0.11.2<1.0:www/rubygem-lograge-rails-gitlab \
	rubygem-grape_logging-gitlab>=1.8.4<2.0:devel/rubygem-grape_logging-gitlab \
	rubygem-gitlab-net-dns>=0.12.0<0.13:dns/rubygem-gitlab-net-dns \
	rubygem-countries>=4.1.3<4.2.0:devel/rubygem-countries \
	rubygem-retriable>=3.1.2<3.2.0:devel/rubygem-retriable \
	rubygem-lru_redux>0:devel/rubygem-lru_redux \
	rubygem-mail>=2.8.1<2.8.2,2:mail/rubygem-mail \
	rubygem-lockbox>=1.3.0<1.4:security/rubygem-lockbox \
	rubygem-valid_email>=0.1<1:mail/rubygem-valid_email \
	rubygem-jsonb_accessor>=1.4<2:www/rubygem-jsonb_accessor \
	rubygem-json-gitlab>=2.11.2<2.12:devel/rubygem-json-gitlab \
	rubygem-json_schemer>=2.3.0<2.4:devel/rubygem-json_schemer \
	rubygem-oj>=3.16.11<3.17:devel/rubygem-oj \
	rubygem-oj-introspect>=0.8<1:devel/rubygem-oj-introspect \
	rubygem-multi_json114>=1.14.1<1.15:devel/rubygem-multi_json114 \
	rubygem-yajl-ruby>=1.4.3<1.5:devel/rubygem-yajl-ruby \
	rubygem-webauthn>=3.0<4:security/rubygem-webauthn \
	rubygem-ipaddress>=0.8.3<0.9:net/rubygem-ipaddress \
	rubygem-parslet1>=1.8<2:textproc/rubygem-parslet1 \
	rubygem-ed25519>=1.4.0<1.5:security/rubygem-ed25519 \
	rubygem-cvss-suite>=3.3.0<3.4:security/rubygem-cvss-suite \
	rubygem-arr-pm>=0.0.12<0.1:devel/rubygem-arr-pm \
	rubygem-devfile>=0.4.4<0.5:net/rubygem-devfile \
	rubygem-hashdiff>=1.2.0<1.3:devel/rubygem-hashdiff \
	rubygem-CFPropertyList-gitlab>=3.0.7<3.1:devel/rubygem-CFPropertyList-gitlab \
	rubygem-app_store_connect>=0:net/rubygem-app_store_connect \
	rubygem-telesignenterprise>=2.2<3:devel/rubygem-telesignenterprise \
	rubygem-net-protocol01>=0.1.3<0.2:net/rubygem-net-protocol01 \
	rubygem-nkf>=0.2.0<0.3:net/rubygem-nkf \
	rubygem-net-http>=0.6.0<0.6.1:www/rubygem-net-http \
	rubygem-uri-gitlab>=0.13.2<0.13.3:net/rubygem-uri-gitlab \
	rubygem-duo_api>=1.4<2:security/rubygem-duo_api \
	rubygem-gitlab-sdk>=0.3.0<0.4:devel/rubygem-gitlab-sdk \
	rubygem-paper_trail>=16.0<17:devel/rubygem-paper_trail \
	rubygem-i18n_data>=0.13.1<1:devel/rubygem-i18n_data \
	rubygem-gitlab-cloud-connector>=1.21<2:security/rubygem-gitlab-cloud-connector \
	rubygem-google-cloud-profiler-v2>=0.3<1:textproc/rubygem-google-cloud-profiler-v2 \
	rubygem-parallel>=1.27.0<2:sysutils/rubygem-parallel \
	rubygem-google-cloud-storage_transfer-gitlab>=1.2.0<1.3:net/rubygem-google-cloud-storage_transfer-gitlab \
	rubygem-minitest>=5.11<6:devel/rubygem-minitest \
	rubygem-grpc-tools>=1.69.0<1.70:net/rubygem-grpc-tools \
	rubygem-opensearch-ruby-gitlab>=0:textproc/rubygem-opensearch-ruby-gitlab

BUILD_DEPENDS=	gem:devel/ruby-gems \
	${MY_DEPENDS}

RUN_DEPENDS=	gmake>=4.4.1:devel/gmake \
	${MY_DEPENDS}

FLAVORS=	ce ee
FLAVOR?=	${FLAVORS:[1]}

USES=		nodejs:env python:run ruby shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
.if ${FLAVOR:U} == ee
GL_PROJECT=	gitlab
.else # ce
GL_PROJECT=	gitlab-foss
.endif

USE_RC_SUBR=	gitlab

SHEBANG_FILES=	gems/bundler-checksum/test/project_with_checksum_lock/scripts/test \
		scripts/build_assets_image \
		scripts/build_qa_image \
		scripts/build_gdk_image \
		scripts/compile_assets \
		scripts/db_tasks \
		scripts/rails-update-bisect \
		scripts/frontend/codemods/vuex-to-pinia/migrate.sh \
		scripts/frontend/execute-on-staged-files.sh \
		scripts/frontend/start_storybook.sh \
		scripts/validate-monorepo-gem \
		.lefthook/gitleaks.sh \
		.lefthook/pre-push/merge_conflicts \
		qa/gdk/entrypoint \
		qa/bin/test \
		vendor/gems/sidekiq/scripts/update-sidekiq.sh

CONFLICTS_INSTALL=	gitolite \
			gitolite2 \
			gogs \
			gitea \
			gitosis

# We install the CE and EE flavor in the same directory
WWWDIR=		${PREFIX}/www/gitlab
NO_ARCH=	yes
NO_BUILD=	yes

USERS=	git
GROUPS=	git

OPTIONS_DEFINE=			KERBEROS
OPTIONS_DEFAULT=		KERBEROS

KERBEROS_BUILD_DEPENDS=		rubygem-timfel-krb5-auth>=0.8<1:security/rubygem-timfel-krb5
KERBEROS_RUN_DEPENDS=		rubygem-timfel-krb5-auth>=0.8<1:security/rubygem-timfel-krb5
KERBEROS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-Gemfile-kerberos-off

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" -e "s|%%LOCALBASE%%|${LOCALBASE}|" -e "s|%%WWWDIR%%|${WWWDIR}|" ${WRKSRC}/config/gitlab.yml.example \
		${WRKSRC}/config/puma.rb.example \
		${WRKSRC}/lib/support/nginx/gitlab \
		${WRKSRC}/lib/support/nginx/gitlab-ssl
	# Remove symlink a create a file with content
	${RM} ${WRKSRC}/GITLAB_WORKHORSE_VERSION
	${ECHO} ${PORTVERSION} > ${WRKSRC}/GITLAB_WORKHORSE_VERSION

do-install:
	${CP} ${WRKSRC}/config/database.yml.postgresql ${WRKSRC}/config/database.yml.sample
	# TODO: Vendored gems are installing binaries not into STAGEDIR, this needs to be fixed.
	# As intermediate solution, the binaries are not disabled by patches
	#(cd ${WRKSRC} && ${RM} Gemfile.lock && bundle config set path ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} && ${WRK_ENV} ${GEM_ENV} bundle install --local)
	(cd ${WRKSRC} && bundle config set --local bin .bin)
	# should skip development and test, but does not work
	#(cd ${WRKSRC} && bundle config set --local without development test)
	#(cd ${WRKSRC} && cat .bundle/config)
	(cd ${WRKSRC} && ${RM} Gemfile.lock && ${WRK_ENV} ${GEM_ENV} bundle install --local)
	(cd ${WRKSRC} && bundle binstubs --all --path .bin)
	${RM} -R ${WRKSRC}/workhorse
	# remove vendored sidekiq gem as it breaks gitlab 17.1.0 for FreeBSD
	# See also: https://gitlab.com/gitlab-org/gitlab/-/issues/468435
	#${RM} -R ${WRKSRC}/vendor/gems/sidekiq-7.1.6
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete
	${FIND} ${WRKSRC} -name '*.gitkeep' -delete
	${FIND} ${WRKSRC} -name '*.gitignore' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	${MV} ${WRKSRC}/config/initializers/relative_url.rb.sample ${WRKSRC}/config/initializers/relative_url.rb.example
	# get files for workdir with: find . -name "*.example" | sort
	${MV} ${WRKSRC}/config/cable.yml.example ${WRKSRC}/config/cable.yml.sample
	${MV} ${WRKSRC}/config/gitlab.yml.example ${WRKSRC}/config/gitlab.yml.sample
	${MV} ${WRKSRC}/config/initializers/devise_password_length.rb.example ${WRKSRC}/config/initializers/devise_password_length.rb.sample
	${MV} ${WRKSRC}/config/puma.rb.example ${WRKSRC}/config/puma.rb.sample
	${MV} ${WRKSRC}/config/redis.yml.example ${WRKSRC}/config/redis.yml.sample
	${MV} ${WRKSRC}/config/resque.yml.example ${WRKSRC}/config/resque.yml.sample
	${MV} ${WRKSRC}/config/secrets.yml.example ${WRKSRC}/config/secrets.yml.sample
	${MV} ${WRKSRC}/config/session_store.yml.example ${WRKSRC}/config/session_store.yml.sample
	${MV} ${WRKSRC}/config/sidekiq.yml.example ${WRKSRC}/config/sidekiq.yml.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab ${WRKSRC}/lib/support/nginx/gitlab.sample
	${MV} ${WRKSRC}/lib/support/nginx/gitlab-ssl ${WRKSRC}/lib/support/nginx/gitlab-ssl.sample
	${MV} ${WRKSRC}/public/robots.txt ${WRKSRC}/public/robots.txt.sample
	${MKDIR} ${STAGEDIR}${WWWDIR}/app/assets/builds
	${MKDIR} ${STAGEDIR}${WWWDIR}/config/helpers/tailwind
	${MKDIR} ${STAGEDIR}${WWWDIR}/public/assets
	${MKDIR} ${STAGEDIR}${WWWDIR}/public/uploads
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/cache
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/sessions
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/backups
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/sockets/private/internal
	${MKDIR} ${STAGEDIR}${WWWDIR}/shared/external-diffs
	${MKDIR} ${STAGEDIR}${WWWDIR}/shared/tmp
	${MKDIR} ${STAGEDIR}${WWWDIR}/shared/artifacts/tmp/work
	${MKDIR} ${STAGEDIR}${WWWDIR}/vendor/assets/stylesheets
	${MKDIR} ${STAGEDIR}${WWWDIR}/workhorse/changelogs/unreleased
	# Skip file having an executable bit
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "-not ( -type f -perm -a=x )")
	# now copy all files having an execution bit and preserve to x bit (this fixes some issues we saw)
	(cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR} "-type f -perm -a=x")

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		/secrets.yml.sample$$/ s#^@sample #@sample(git,www,0600) #; \
		/database.yml.sample$$/ s#^@sample #@sample(git,www,0600) #; \
		s#${WWWDIR_REL}/bin#@(git,,544) ${WWWDIR_REL}/bin#; \
		/db\/schema.rb$$|gitlab.po$$|gitlab.pot$$|gitlab.po.time_stamp$$|locale\/index.js$$/ s#^#@(git,,) #;' >> ${TMPPLIST}
	@${ECHO_CMD} "@owner git" >> ${TMPPLIST}
	@${ECHO_CMD} "@group www" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(git,git) ${WWWDIR_REL}/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/app/assets/builds/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/app/assets/images/auth_buttons/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/app/assets/javascripts/locale/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/app/assets/javascripts/pipeline_wizard/templates/" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(git,git,554) ${WWWDIR_REL}/bin" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/config" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(git,git,755) ${WWWDIR_REL}/config/helpers/tailwind" >> ${TMPPLIST}
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
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/api/8_monitor" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/browser_ui/5_package" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/qa/specs/features/browser_ui/8_monitor" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/qa/tmp" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/spec/support/gitlab-git-test.git/refs/heads" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${WWWDIR_REL}/spec/support/gitlab-git-test.git/refs/tags" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,755) ${WWWDIR_REL}/shared" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts/tmp" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/artifacts/tmp/work" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/ci_secure_files" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/shared/packages" >> ${TMPPLIST}
	@${ECHO_CMD} "@group gitlab-pages" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/shared/pages" >> ${TMPPLIST}
	@${ECHO_CMD} "@group www" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/terraform_state" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,700) ${WWWDIR_REL}/shared/external-diffs" >> ${TMPPLIST}
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
	#@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/run" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sessions" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sockets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sockets/private" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/tmp/sockets/private/internal" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/vendor" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/vendor/assets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/vendor/assets/stylesheets" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,770) ${WWWDIR_REL}/workhorse/changelogs/unreleased" >> ${TMPPLIST}
.if ${FLAVOR:U} == ee
	# Gitlab-ee version
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/ee/db/active_context/migrate" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/gems/gitlab-backup-cli/tmp" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/qa/qa/specs/features/ee/api/4_verify" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/qa/qa/specs/features/ee/api/5_package" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(,,744) ${WWWDIR_REL}/qa/qa/specs/features/ee/api/8_monitor" >> ${TMPPLIST}
.endif

.if !defined(_GITLAB_MAKESUM_GUARD)
makesum:
	${MAKE} -D_GITLAB_MAKESUM_GUARD makesum DISTINFO_FILE=${.CURDIR}/distinfo FLAVOR=ce
	${MAKE} -D_GITLAB_MAKESUM_GUARD makesum DISTINFO_FILE=${.CURDIR}/distinfo.ee FLAVOR=ee
	${CAT} ${.CURDIR}/distinfo.ee >> ${.CURDIR}/distinfo
	${RM} ${.CURDIR}/distinfo.ee
	(cd ../../devel/gitaly && ${MAKE} makesum)
	(cd ../../net/gitlab-agent && ${MAKE} makesum)
	(cd ../../www/gitlab-pages && ${MAKE} makesum)
	(cd ../../www/gitlab-workhorse && ${MAKE} makesum)
	(cd ../../net/rubygem-gitlab-kas-grpc && ${MAKE} makesum)
	(cd ../../www/rubygem-rails-gitlab && ${MAKE} makesum)
	(cd ../../www/rubygem-actioncable-gitlab && ${MAKE} makesum)
	(cd ../../mail/rubygem-actionmailbox-gitlab && ${MAKE} makesum)
	(cd ../../mail/rubygem-actionmailer-gitlab && ${MAKE} makesum)
	(cd ../../www/rubygem-actionpack-gitlab && ${MAKE} makesum)
	(cd ../../textproc/rubygem-actiontext-gitlab && ${MAKE} makesum)
	(cd ../../devel/rubygem-actionview-gitlab && ${MAKE} makesum)
	(cd ../../devel/rubygem-activejob-gitlab && ${MAKE} makesum)
	(cd ../../databases/rubygem-activemodel-gitlab && ${MAKE} makesum)
	(cd ../../databases/rubygem-activerecord-gitlab && ${MAKE} makesum)
	(cd ../../net/rubygem-activestorage-gitlab && ${MAKE} makesum)
	(cd ../../devel/rubygem-activesupport-gitlab && ${MAKE} makesum)
	(cd ../../www/rubygem-railties-gitlab && ${MAKE} makesum)
	(cd ../../databases/rubygem-globalid-rails-gitlab && ${MAKE} makesum)
	(cd ../../www/rubygem-responders-rails-gitlab && ${MAKE} makesum)

.endif

.include "${.CURDIR}/Makefile.common"
.include <bsd.port.mk>
