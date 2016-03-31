# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	gitlab
PORTVERSION=	8.5.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www devel

MAINTAINER=	ports@toco-domains.de
COMMENT=	Web GUI for managing git repositories

LICENSE=	MIT

BUILD_DEPENDS=	ruby>=2.1.8:${PORTSDIR}/lang/ruby21 \
	gem:${PORTSDIR}/devel/ruby-gems
RUN_DEPENDS=	git>=2.4.3:${PORTSDIR}/devel/git \
	gitlab-shell>=2.6.10:${PORTSDIR}/devel/gitlab-shell\
	gitlab-workhorse>=0.6.4:${PORTSDIR}/www/gitlab-workhorse \
	redis>=2.8.23:${PORTSDIR}/databases/redis \
	rubygem-rails4>=4.2.5.2:${PORTSDIR}/www/rubygem-rails4 \
	rubygem-rails-deprecated_sanitizer>=1.0.3:${PORTSDIR}/devel/rubygem-rails-deprecated_sanitizer \
	rubygem-responders>=2.0:${PORTSDIR}/www/rubygem-responders \
	rubygem-sprockets>=2.12.3:${PORTSDIR}/devel/rubygem-sprockets \
	rubygem-default_value_for>=3.0.1:${PORTSDIR}/devel/rubygem-default_value_for \
	rubygem-pg>=0.18.2:${PORTSDIR}/databases/rubygem-pg \
	rubygem-devise-rails4>=3.5.4:${PORTSDIR}/devel/rubygem-devise-rails4 \
	rubygem-devise-async-rails4>=0.9.0:${PORTSDIR}/devel/rubygem-devise-async-rails4 \
	rubygem-doorkeeper>=2.2.0:${PORTSDIR}/security/rubygem-doorkeeper \
	rubygem-omniauth>=1.3.1:${PORTSDIR}/security/rubygem-omniauth \
	rubygem-omniauth-azure-oauth2>=0.0.6:${PORTSDIR}/net/rubygem-omniauth-azure-oauth2 \
	rubygem-omniauth-bitbucket>=0.0.2:${PORTSDIR}/security/rubygem-omniauth-bitbucket \
	rubygem-omniauth-cas3>=1.1.2:${PORTSDIR}/security/rubygem-omniauth-cas3 \
	rubygem-omniauth-facebook>=3.0.0:${PORTSDIR}/net/rubygem-omniauth-facebook \
	rubygem-omniauth-github>=1.1.1:${PORTSDIR}/net/rubygem-omniauth-github \
	rubygem-omniauth-gitlab>=1.0.0:${PORTSDIR}/security/rubygem-omniauth-gitlab \
	rubygem-omniauth-google-oauth2>=0.2.0:${PORTSDIR}/net/rubygem-omniauth-google-oauth2 \
	rubygem-omniauth-saml>=1.4.2:${PORTSDIR}/security/rubygem-omniauth-saml \
	rubygem-omniauth-shibboleth>=1.2.0:${PORTSDIR}/security/rubygem-omniauth-shibboleth \
	rubygem-omniauth-twitter>=1.2.0:${PORTSDIR}/net/rubygem-omniauth-twitter \
	rubygem-omniauth_crowd>=2.2.0:${PORTSDIR}/devel/rubygem-omniauth_crowd \
	rubygem-rack-oauth2>=1.2.1:${PORTSDIR}/security/rubygem-rack-oauth2 \
	rubygem-recaptcha>=0:${PORTSDIR}/devel/rubygem-recaptcha \
	rubygem-akismet>=2.0:${PORTSDIR}/devel/rubygem-akismet \
	rubygem-devise-two-factor>=2.0.0:${PORTSDIR}/security/rubygem-devise-two-factor \
	rubygem-rqrcode-rails3>=0.1.7:${PORTSDIR}/www/rubygem-rqrcode-rails3 \
	rubygem-attr_encrypted>=1.3.4:${PORTSDIR}/security/rubygem-attr_encrypted \
	rubygem-browser>=1.0.0:${PORTSDIR}/www/rubygem-browser \
	rubygem-gitlab_git>=8.2:${PORTSDIR}/devel/rubygem-gitlab_git \
	rubygem-gitlab_omniauth-ldap>=1.2.1:${PORTSDIR}/net/rubygem-gitlab_omniauth-ldap \
	rubygem-gollum-lib>=4.1.0:${PORTSDIR}/www/rubygem-gollum-lib \
	rubygem-github-linguist>=4.7.0:${PORTSDIR}/textproc/rubygem-github-linguist \
	rubygem-grape>=0.13.0:${PORTSDIR}/devel/rubygem-grape \
	rubygem-grape-entity>=0.4.2:${PORTSDIR}/devel/rubygem-grape-entity \
	rubygem-rack-cors>=0.4.0:${PORTSDIR}/www/rubygem-rack-cors \
	rubygem-kaminari-rails4>=0.16.3:${PORTSDIR}/www/rubygem-kaminari-rails4 \
	rubygem-haml-rails-rails4>=0.9.0:${PORTSDIR}/www/rubygem-haml-rails-rails4 \
	rubygem-carrierwave>=0.9.0:${PORTSDIR}/www/rubygem-carrierwave \
	rubygem-dropzonejs-rails>=0.7.1:${PORTSDIR}/www/rubygem-dropzonejs-rails \
	rubygem-fog>=1.36:${PORTSDIR}/devel/rubygem-fog \
	rubygem-unf>=0.1.4:${PORTSDIR}/textproc/rubygem-unf \
	rubygem-six>=0.2.0:${PORTSDIR}/security/rubygem-six \
	rubygem-seed-fu>=2.3.5:${PORTSDIR}/databases/rubygem-seed-fu \
	rubygem-html-pipeline1>=1.11.0:${PORTSDIR}/textproc/rubygem-html-pipeline1 \
	rubygem-task_list>=1.0.2:${PORTSDIR}/www/rubygem-task_list \
	rubygem-github-markup>=1.3.1:${PORTSDIR}/textproc/rubygem-github-markup \
	rubygem-redcarpet>=3.3.3:${PORTSDIR}/textproc/rubygem-redcarpet \
	rubygem-redcloth>=4.2.9:${PORTSDIR}/www/rubygem-redcloth \
	rubygem-rdoc>=3.6:${PORTSDIR}/devel/rubygem-rdoc \
	rubygem-org-ruby>=0.9.12:${PORTSDIR}/textproc/rubygem-org-ruby \
	rubygem-creole>=0.5.0:${PORTSDIR}/textproc/rubygem-creole \
	rubygem-wikicloth>=0.8.1:${PORTSDIR}/textproc/rubygem-wikicloth \
	rubygem-asciidoctor>=1.5.2:${PORTSDIR}/textproc/rubygem-asciidoctor \
	rubygem-rouge>=1.10.1:${PORTSDIR}/textproc/rubygem-rouge \
	rubygem-nokogiri>=1.6.7.2:${PORTSDIR}/textproc/rubygem-nokogiri  \
	rubygem-diffy>=3.0.3:${PORTSDIR}/textproc/rubygem-diffy \
	rubygem-unicorn>=4.8.2:${PORTSDIR}/www/rubygem-unicorn \
	rubygem-unicorn-worker-killer>=0.4.2:${PORTSDIR}/www/rubygem-unicorn-worker-killer \
	rubygem-state_machines-activerecord>=0.3.0:${PORTSDIR}/databases/rubygem-state_machines-activerecord \
	rubygem-after_commit_queue>=0:${PORTSDIR}/databases/rubygem-after_commit_queue \
	rubygem-acts-as-taggable-on3>=3.4.0:${PORTSDIR}/www/rubygem-acts-as-taggable-on3 \
	rubygem-sinatra>=1.4.4:${PORTSDIR}/www/rubygem-sinatra \
	rubygem-sidekiq>=4.0:${PORTSDIR}/devel/rubygem-sidekiq \
	rubygem-sidekiq-cron>=0.4.0:${PORTSDIR}/devel/rubygem-sidekiq-cron \
	rubygem-redis-namespace>=0:${PORTSDIR}/databases/rubygem-redis-namespace \
	rubygem-httparty>=0.13.3:${PORTSDIR}/www/rubygem-httparty \
	rubygem-colorize>=0.7.0:${PORTSDIR}/devel/rubygem-colorize \
	rubygem-settingslogic>=2.0.9:${PORTSDIR}/devel/rubygem-settingslogic \
	rubygem-version_sorter>=2.0.0:${PORTSDIR}/textproc/rubygem-version_sorter \
	rubygem-redis-rails>=4.0.0:${PORTSDIR}/www/rubygem-redis-rails \
	rubygem-tinder>=1.10.0:${PORTSDIR}/net-im/rubygem-tinder \
	rubygem-hipchat>=1.5.0:${PORTSDIR}/net-im/rubygem-hipchat \
	rubygem-gitlab-flowdock-git-hook>=1.0.1:${PORTSDIR}/www/rubygem-gitlab-flowdock-git-hook \
	rubygem-gemnasium-gitlab-service>=0.2:${PORTSDIR}/devel/rubygem-gemnasium-gitlab-service \
	rubygem-slack-notifier>=1.2.0:${PORTSDIR}/devel/rubygem-slack-notifier \
	rubygem-asana>=0.4.0:${PORTSDIR}/www/rubygem-asana \
	rubygem-ruby-fogbugz>=0.2.1:${PORTSDIR}/devel/rubygem-ruby-fogbugz \
	rubygem-d3_rails-rails4>=3.5.0:${PORTSDIR}/www/rubygem-d3_rails-rails4 \
	rubygem-cal-heatmap-rails-rails4>=3.5.0:${PORTSDIR}/www/rubygem-cal-heatmap-rails-rails4 \
	rubygem-underscore-rails>=1.8.0:${PORTSDIR}/www/rubygem-underscore-rails \
	rubygem-sanitize>=2.0:${PORTSDIR}/textproc/rubygem-sanitize \
	rubygem-babosa>=1.0.2:${PORTSDIR}/textproc/rubygem-babosa \
	rubygem-loofah>=2.0.3:${PORTSDIR}/textproc/rubygem-loofah \
	rubygem-rack-attack>=4.3.1:${PORTSDIR}/www/rubygem-rack-attack \
	rubygem-ace-rails-ap>=2.0.1:${PORTSDIR}/www/rubygem-ace-rails-ap \
	rubygem-mousetrap-rails>=1.4.6:${PORTSDIR}/www/rubygem-mousetrap-rails \
	rubygem-charlock_holmes>=0.7.3:${PORTSDIR}/textproc/rubygem-charlock_holmes \
	rubygem-sass-rails5>=5.0.0:${PORTSDIR}/textproc/rubygem-sass-rails5 \
	rubygem-coffee-rails4>=4.1.0:${PORTSDIR}/devel/rubygem-coffee-rails4 \
	rubygem-uglifier>=2.7.2:${PORTSDIR}/www/rubygem-uglifier \
	rubygem-turbolinks>=2.5.0:${PORTSDIR}/www/rubygem-turbolinks \
	rubygem-jquery-turbolinks>=2.1.0:${PORTSDIR}/www/rubygem-jquery-turbolinks \
	rubygem-addressable>=2.3.8:${PORTSDIR}/www/rubygem-addressable \
	rubygem-bootstrap-sass>=3.3.0:${PORTSDIR}/www/rubygem-bootstrap-sass \
	rubygem-font-awesome-rails-rails4>=4.2:${PORTSDIR}/devel/rubygem-font-awesome-rails-rails4 \
	rubygem-gitlab_emoji>=0.3:${PORTSDIR}/graphics/rubygem-gitlab_emoji \
	rubygem-gon>=6.0.1:${PORTSDIR}/www/rubygem-gon \
	rubygem-jquery-atwho-rails-rails4>=1.3.2:${PORTSDIR}/www/rubygem-jquery-atwho-rails-rails4 \
	rubygem-jquery-rails4>=4.0.0:${PORTSDIR}/www/rubygem-jquery-rails4 \
	rubygem-jquery-scrollto-rails>=1.4.3:${PORTSDIR}/www/rubygem-jquery-scrollto-rails \
	rubygem-jquery-ui-rails-rails4>=5.0.0:${PORTSDIR}/www/rubygem-jquery-ui-rails-rails4 \
	rubygem-nprogress-rails>=0.1.6.7:${PORTSDIR}/devel/rubygem-nprogress-rails \
	rubygem-raphael-rails>=2.1.2:${PORTSDIR}/www/rubygem-raphael-rails \
	rubygem-request_store>=1.2.0:${PORTSDIR}/devel/rubygem-request_store \
	rubygem-select2-rails>=3.5.9:${PORTSDIR}/www/rubygem-select2-rails \
	rubygem-virtus>=1.0.1:${PORTSDIR}/devel/rubygem-virtus \
	rubygem-net-ssh>=3.0.1:${PORTSDIR}/security/rubygem-net-ssh \
	rubygem-sentry-raven>=0.15.4:${PORTSDIR}/devel/rubygem-sentry-raven \
	rubygem-gitlab_meta>=7.0:${PORTSDIR}/devel/rubygem-gitlab_meta \
	rubygem-newrelic_rpm>=3.9.4.245:${PORTSDIR}/devel/rubygem-newrelic_rpm \
	rubygem-newrelic-grape>=0:${PORTSDIR}/devel/rubygem-newrelic-grape \
	rubygem-newrelic_rpm>=3.14:${PORTSDIR}/devel/rubygem-newrelic_rpm \
	rubygem-octokit>=3.8.0:${PORTSDIR}/net/rubygem-octokit \
	rubygem-mail_room>=0.6.1:${PORTSDIR}/mail/rubygem-mail_room \
	rubygem-email_reply_parser>=0.5.8:${PORTSDIR}/mail/rubygem-email_reply_parser \
	rubygem-activerecord-deprecated_finders>=1.0.3:${PORTSDIR}/devel/rubygem-activerecord-deprecated_finders \
	rubygem-activerecord-session_store>=0.1.0:${PORTSDIR}/databases/rubygem-activerecord-session_store \
	rubygem-nested_form>=0.3.2:${PORTSDIR}/www/rubygem-nested_form \
	rubygem-oauth2>=1.0.0:${PORTSDIR}/net/rubygem-oauth2 \
	rubygem-paranoia>=2.0:${PORTSDIR}/databases/rubygem-paranoia \
	rubygem-rinku>=1.7.3:${PORTSDIR}/www/rubygem-rinku

USE=	pgsql=yes
WANT=	pgsql=9.1+

USE_RC_SUBR=	gitlab
USE_GITHUB=	yes
GH_ACCOUNT=	gitlabhq
GH_PROJECT=	gitlabhq

USERS=	git
GROUPS=	git

.include <bsd.port.options.mk>

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete
	${FIND} ${WRKSRC} -name '*.gitkeep' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	${MV} ${WRKSRC}/config/gitlab.yml.example ${WRKSRC}/config/gitlab.yml.sample
	${MV} ${WRKSRC}/config/unicorn.rb.example ${WRKSRC}/config/unicorn.rb.sample
	${MV} ${WRKSRC}/config/resque.yml.example ${WRKSRC}/config/resque.yml.sample
	${MV} ${WRKSRC}/config/secrets.yml.example ${WRKSRC}/config/secrets.yml.sample
	${MV} ${WRKSRC}/config/initializers/rack_attack.rb.example ${WRKSRC}/config/initializers/rack_attack.rb.sample
	${CP} ${WRKSRC}/config/database.yml.postgresql ${WRKSRC}/config/database.yml.sample

post-install:
	${MKDIR} ${STAGEDIR}/home/git/repositories
	${MKDIR} ${STAGEDIR}/home/git/gitlab-satellites
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/public/assets
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/cache
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/tmp/sessions
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

.include <bsd.port.mk>
