# New ports collection makefile for:	p5-Gantry
# Date created:		2006-09-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Gantry
PORTVERSION=	3.54
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web application framework for mod_perl, cgi, etc

BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/CGI/Simple.pm:${PORTSDIR}/www/p5-CGI-Simple \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
		${SITE_PERL}/File/Copy/Recursive.pm:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		${SITE_PERL}/Hash/Merge.pm:${PORTSDIR}/textproc/p5-Hash-Merge \
		${SITE_PERL}/HTML/Prototype.pm:${PORTSDIR}/www/p5-HTML-Prototype \
		${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		p5-Sub-Install>0:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Mail-RFC822-Address>0:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
		p5-Config-General>0:${PORTSDIR}/devel/p5-Config-General \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Template-Toolkit>=2.0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Template-Plugin-HTML-SuperForm>0:${PORTSDIR}/textproc/p5-Template-Plugin-HTML-SuperForm
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/CGI/Simple.pm:${PORTSDIR}/www/p5-CGI-Simple \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
		${SITE_PERL}/File/Copy/Recursive.pm:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		${SITE_PERL}/Hash/Merge.pm:${PORTSDIR}/textproc/p5-Hash-Merge \
		${SITE_PERL}/HTML/Prototype.pm:${PORTSDIR}/www/p5-HTML-Prototype \
		${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		p5-Sub-Install>0:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Mail-RFC822-Address>0:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
		p5-Config-General>0:${PORTSDIR}/devel/p5-Config-General \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Template-Toolkit>=2.0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Template-Plugin-HTML-SuperForm>0:${PORTSDIR}/textproc/p5-Template-Plugin-HTML-SuperForm

PERL_MODBUILD=	5.8.0+

WWWDIR=		${PREFIX}/www/${PORTNAME:L}

MAN3=		Gantry.3 \
		Gantry::Build.3 \
		Gantry::Conf.3 \
		Gantry::Conf::FAQ.3 \
		Gantry::Conf::Provider.3 \
		Gantry::Conf::Provider::FlatFile::Config::General.3 \
		Gantry::Conf::Provider::FlatFile::Config::Tiny.3 \
		Gantry::Conf::Provider::HTTP.3 \
		Gantry::Conf::Provider::HTTP::Config::General.3 \
		Gantry::Conf::Provider::ParamBuilder.3 \
		Gantry::Conf::Provider::PerlSetVar.3 \
		Gantry::Conf::Provider::SQL::PostgreSQL.3 \
		Gantry::Conf::Tutorial.3 Gantry::Control.3 \
		Gantry::Control::C::Access.3 \
		Gantry::Control::C::AuthenBase.3 \
		Gantry::Control::C::AuthenCDBI.3 \
		Gantry::Control::C::AuthenRegular.3 \
		Gantry::Control::C::Authz::PageBasedBase.3 \
		Gantry::Control::C::Authz::PageBasedCDBI.3 \
		Gantry::Control::C::Authz::PageBasedRegular.3 \
		Gantry::Control::C::AuthzBase.3 \
		Gantry::Control::C::AuthzCDBI.3 \
		Gantry::Control::C::AuthzRegular.3 \
		Gantry::Control::C::Groups.3 Gantry::Control::C::Pages.3 \
		Gantry::Control::C::Users.3 \
		Gantry::Control::Model::GEN::auth_group_members.3 \
		Gantry::Control::Model::GEN::auth_groups.3 \
		Gantry::Control::Model::GEN::auth_pages.3 \
		Gantry::Control::Model::GEN::auth_users.3 \
		Gantry::Control::Model::auth_group_members.3 \
		Gantry::Control::Model::auth_group_members_cdbi.3 \
		Gantry::Control::Model::auth_groups.3 \
		Gantry::Control::Model::auth_groups_cdbi.3 \
		Gantry::Control::Model::auth_pages.3 \
		Gantry::Control::Model::auth_pages_cdbi.3 \
		Gantry::Control::Model::auth_users.3 \
		Gantry::Control::Model::auth_users_cdbi.3 \
		Gantry::Docs.3 Gantry::Docs::Tutorial.3 \
		Gantry::Docs::About.3 Gantry::Docs::DBConn.3 \
		Gantry::Docs::Cookbook.3 \
		Gantry::Docs::FAQ.3 Gantry::Docs::QuickStart.3 \
		Gantry::Docs::Why.3 Gantry::Engine::CGI.3 \
		Gantry::Engine::MP13.3 Gantry::Engine::MP20.3 \
		Gantry::Exception.3 \
		Gantry::Init.3 Gantry::Plugins::AutoCRUD.3 \
		Gantry::Plugins::AjaxCRUD.3 \
		Gantry::Plugins::AjaxFORM.3 \
		Gantry::Plugins::AuthCookie.3 \
		Gantry::Plugins::AutoCRUDHelper::CDBI.3 \
		Gantry::Plugins::AutoCRUDHelper::DBIxClass.3 \
		Gantry::Plugins::CRUD.3 Gantry::Plugins::Calendar.3 \
		Gantry::Plugins::Cache.3 \
		Gantry::Plugins::Cache::FastMmap.3 \
		Gantry::Plugins::Cache::Memcached.3 \
		Gantry::Plugins::Cache::Storable.3 \
		Gantry::Plugins::DBIxClassConn.3 Gantry::Plugins::Static.3 \
		Gantry::Plugins::PageCache.3 \
		Gantry::Plugins::SOAP::Doc.3 \
		Gantry::Plugins::SOAP::RPC.3 \
		Gantry::Plugins::Session.3 \
		Gantry::Plugins::Validate.3 Gantry::Server.3 Gantry::Stash.3 \
		Gantry::Stash::Controller.3 Gantry::Stash::View.3 \
		Gantry::Stash::View::Form.3 Gantry::State::Simple.3 \
		Gantry::State::Default.3 Gantry::Template::Default.3 \
		Gantry::State::Exceptions.3 \
		Gantry::Template::Framing.3 Gantry::Template::TT.3 \
		Gantry::Utils::AuthCDBI.3 Gantry::Utils::CDBI.3 \
		Gantry::Utils::CRON.3 \
		Gantry::Utils::CRUDHelp.3 Gantry::Utils::Crypt.3 \
		Gantry::Utils::Captcha.3\
		Gantry::Utils::DB.3 \
		Gantry::Utils::DBConnHelper.3 \
		Gantry::Utils::DBConnHelper::MP13.3 \
		Gantry::Utils::DBConnHelper::MP20.3 \
		Gantry::Utils::DBConnHelper::Script.3 \
		Gantry::Utils::DBIxClass.3 Gantry::Utils::FormErrors.3 Gantry::Utils::HTML.3 \
		Gantry::Utils::FormMunger.3 \
		Gantry::Utils::Model.3 Gantry::Utils::Model::Auth.3 \
		Gantry::Utils::Model::Regular.3 Gantry::Utils::ModelHelper.3 \
		Gantry::Utils::PODViewer.3 Gantry::Utils::PerlbalFixup.3 \
		Gantry::Utils::SQL.3 Gantry::Utils::Validate.3 \
		Gantry::Utils::TablePerms.3 \
		Gantry::Utils::Threeway.3 \
		Template::Plugin::GantryAuthCookie.3

post-patch:
	${REINPLACE_CMD} -e 's,/home/httpd/html/gantry,${WWWDIR},g' -e 's,\$ENV{'GANTRY_TEMPLATE_PATH'},${WWWDIR},g' ${WRKSRC}/Build.PL

pre-configure:
	@${MKDIR} ${WWWDIR}

post-build:
	@${RMDIR} ${WWWDIR}

pre-install:
	@${MKDIR} ${WWWDIR}

.include <bsd.port.mk>
