# New ports collection makefile for:	www/p5-Jifty
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jifty
PORTVERSION=	0.51228
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Jifty
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Jifty -- Just Do It -- Yet another web framework

BUILD_DEPENDS=	\
		p5-Apache-Session>0:${PORTSDIR}/www/p5-Apache-Session \
		p5-App-CLI>=0.02:${PORTSDIR}/devel/p5-App-CLI \
		p5-Cache-Cache>0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-CGI.pm>0:${PORTSDIR}/www/p5-CGI.pm \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Clone>0:${PORTSDIR}/devel/p5-Clone \
		p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Digest-MD5>0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Email-Folder>0:${PORTSDIR}/mail/p5-Email-Folder \
		p5-Email-LocalDelivery>0:${PORTSDIR}/mail/p5-Email-LocalDelivery \
		p5-Email-Send>=2.00:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-Simple>0:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Email-Simple-Creator>0:${PORTSDIR}/mail/p5-Email-Simple-Creator \
		p5-File-ShareDir>0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-Getopt-Long>=2.34:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Mason>=1.31.0.1:${PORTSDIR}/www/p5-HTML-Mason \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Server-Simple>=0.10:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Mason>=0.09:${PORTSDIR}/www/p5-HTTP-Server-Simple-Mason \
		p5-HTTP-Server-Simple-Recorder>0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Recorder \
		p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Hook-LexWrap>0:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-Jifty-DBI>0.06:${PORTSDIR}/databases/p5-Jifty-DBI \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Locale-Maketext-Simple>0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Pluggable>=2.95:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Module-Refresh>0:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-Pod-Parser>0:${PORTSDIR}/textproc/p5-Pod-Parser \
		p5-Pod-Simple>0:${PORTSDIR}/textproc/p5-Pod-Simple \
		p5-String-Koremutake>0:${PORTSDIR}/textproc/p5-String-Koremutake \
		p5-Test-Base>0:${PORTSDIR}/devel/p5-Test-Base \
		p5-Test-HTTP-Server-Simple>=0.02:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple \
		p5-Test-Pod-Coverage>0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-HTML-Lint>0:${PORTSDIR}/www/p5-HTML-Lint \
		p5-Test-WWW-Mechanize>0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-Time-modules>0:${PORTSDIR}/devel/p5-Time-modules \
		p5-Time-HiRes>0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.12:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-version>0:${PORTSDIR}/devel/p5-version \
		p5-XML-Writer>0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-XPath>0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	\
	Email::Send::Jifty::Test.3 \
	Jifty.3 \
	Jifty::Action.3 \
	Jifty::Action::Autocomplete.3 \
	Jifty::Action::Record.3 \
	Jifty::Action::Record::Create.3 \
	Jifty::Action::Record::Delete.3 \
	Jifty::Action::Record::Update.3 \
	Jifty::Action::Redirect.3 \
	Jifty::Bootstrap.3 \
	Jifty::ClassLoader.3 \
	Jifty::Collection.3 \
	Jifty::Config.3 \
	Jifty::Continuation.3 \
	Jifty::CurrentUser.3 \
	Jifty::Everything.3 \
	Jifty::Handle.3 \
	Jifty::Handler.3 \
	Jifty::I18N.3 \
	Jifty::JSON.3 \
	Jifty::JSON::Converter.3 \
	Jifty::JSON::Parser.3 \
	Jifty::LetMe.3 \
	Jifty::Logger.3 \
	Jifty::Manual::AccessControl.3 \
	Jifty::Manual::Glossary.3 \
	Jifty::Manual::Tutorial.3 \
	Jifty::Model::Schema.3 \
	Jifty::Notification.3 \
	Jifty::Object.3 \
	Jifty::Record.3 \
	Jifty::Request.3 \
	Jifty::Request::Mapper.3 \
	Jifty::Response.3 \
	Jifty::Result.3 \
	Jifty::RightsFrom.3 \
	Jifty::Script::App.3 \
	Jifty::Script::FastCGI.3 \
	Jifty::Script::Help.3 \
	Jifty::Script::Model.3 \
	Jifty::Script::Schema.3 \
	Jifty::Script::Server.3 \
	Jifty::Server.3 \
	Jifty::Test::WWW::Mechanize.3 \
	Jifty::Upgrade.3 \
	Jifty::Util.3 \
	Jifty::Web.3 \
	Jifty::Web::Form::Clickable.3 \
	Jifty::Web::Form::Element.3 \
	Jifty::Web::Form::Field.3 \
	Jifty::Web::Form::Field::Text.3 \
	Jifty::Web::Form::Link.3 \
	Jifty::Web::PageRegion.3 \
	Jifty::Web::Session.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500803
IGNORE=		requires perl 5.8.3 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
