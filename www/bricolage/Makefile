# New ports collection makefile for:	bricolage
# Date created:				May 20, 2004
# Whom:	      				Rod Taylor ports@rbt.ca
#
# $FreeBSD$
#

PORTNAME=	bricolage
PORTVERSION=	1.8.0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bricolage

MAINTAINER=	ports@rbt.ca
COMMENT=	A full-featured, open-source content-management and publishing system

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13-modperl \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg \
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM \
		${SITE_PERL}/Cache/Cache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/${PERL_ARCH}/Cache/Mmap.pm:${PORTSDIR}/devel/p5-Cache-Mmap \
		${SITE_PERL}/Class/Container.pm:${PORTSDIR}/devel/p5-Class-Container \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/Test/Class.pm:${PORTSDIR}/devel/p5-Test-Class \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info \
		${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq-static \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/MasonX/Interp/WithCallbacks.pm:${PORTSDIR}/www/p5-MasonX-Interp-WithCallbacks \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/HTTP/BrowserDetect.pm:${PORTSDIR}/www/p5-HTTP-BrowserDetect
RUN_DEPENDS=	${BUILD_DEPENDS}

APXS?=		${LOCALBASE}/sbin/apxs

MAKE_ENV+=	INSTALL_VERBOSITY="QUIET"

USE_REINPLACE=	yes
PERL_CONFIGURE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

# Needs perl 5.8.x or later for decent unicode support
# Easier to make this a requirement than deal with issues
# for unicode users
.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

# Optional dependencies. Use them if they're installed.
.if exists(${SITE_PERL}/HTML/Template/Expr.pm)
BUILD_DEPENDS+=	${SITE_PERL}/HTML/Template/Expr.pm:${PORTSDIR}/www/p5-HTML-Template-Expr
# HTML::Template::Expr depends on HTML::Template
.endif

.if exists(${SITE_PERL}/${PERL_ARCH}/Template.pm)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
.endif

.if ${PERL_LEVEL} >= 500600 && ${PERL_LEVEL} < 500800
.if exists(${SITE_PERL}/Encode/compat.pm)
BUILD_DEPENDS+=	${SITE_PERL}/Encode/compat.pm:${PORTSDIR}/devel/p5-Encode-compat
.endif
.endif

.if exists(${SITE_PERL}/Test/Pod.pm)
BUILD_DEPENDS+=	${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod
# Test::Pod depends on Pod::Simple
.endif

.if exists(${SITE_PERL}/Devel/Profiler.pm)
BUILD_DEPENDS+=	${SITE_PERL}/Devel/Profiler.pm:${PORTSDIR}/devel/p5-Devel-Profiler
.endif

.if exists(${SITE_PERL}/Net/FTPServer/RO/Server.pm)
BUILD_DEPENDS+=	${SITE_PERL}/Net/FTPServer/RO/Server.pm:${PORTSDIR}/ftp/p5-Net-FTPServer
.endif

.if exists(${SITE_PERL}/Net/SFTP.pm)
BUILD_DEPENDS+=	${SITE_PERL}/Net/SFTP.pm:${PORTSDIR}/net/p5-Net-SFTP
.endif

.if exists(${SITE_PERL}/HTTP/DAV.pm)
BUILD_DEPENDS+=	${SITE_PERL}/HTTP/DAV.pm:${PORTSDIR}/www/p5-HTTP-DAV
.endif

# FIXME: Inclusion of the below results in the error "Unassociated shell command"
#.if exists(${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm)
#BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay
#.endif

.if exists(${SITE_PERL}/${PERL_ARCH}/Imager.pm)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager
.endif

.if exists(${SITE_PERL}/XML/DOM.pm)
BUILD_DEPENDS+=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM
.endif

.if exists(libexec/apache/libperl.so)
IGNORE=		Port requires apache with static mod_perl (www/apache13-modperl)
.endif

MAN1=		bric_queued.1 bric_dbprof.1 bric_republish.1 bric_dev_sync.1 \
		bric_pgimport.1 bric_ftpd.1 bric_clean_tmp.1 bric_dist_mon.1 \
		bric_apachectl.1 bric_soap.1

MAN3=		Bric.3 Bric::Admin.3 Bric::AdvTemplates.3 Bric::Alert.3 \
		Bric::App::AccessHandler.3 Bric::App::ApacheConfig.3 \
		Bric::App::ApacheHandler.3 Bric::App::ApacheStartup.3 Bric::App::Auth.3 \
		Bric::App::Authz.3 Bric::App::Cache.3 Bric::App::CleanupHandler.3 \
		Bric::App::Event.3 Bric::App::Handler.3 Bric::App::MediaFunc.3 \
		Bric::App::PreviewHandler.3 Bric::App::Session.3 Bric::App::Util.3 \
		Bric::AssetEditing.3 Bric::Biz::ATType.3 Bric::Biz::Asset.3 \
		Bric::Biz::Asset::Business.3 Bric::Biz::Asset::Business::Media.3 \
		Bric::Biz::Asset::Business::Media::Audio.3 \
		Bric::Biz::Asset::Business::Media::Image.3 \
		Bric::Biz::Asset::Business::Media::Video.3 \
		Bric::Biz::Asset::Business::Parts::Tile.3 \
		Bric::Biz::Asset::Business::Parts::Tile::Container.3 \
		Bric::Biz::Asset::Business::Parts::Tile::Data.3 \
		Bric::Biz::Asset::Business::Story.3 Bric::Biz::Asset::Formatting.3 \
		Bric::Biz::AssetType.3 Bric::Biz::AssetType::Parts::Data.3 \
		Bric::Biz::Category.3 Bric::Biz::Contact.3 Bric::Biz::Keyword.3 \
		Bric::Biz::Org.3 Bric::Biz::Org::Parts::Addr.3 Bric::Biz::Org::Person.3 \
		Bric::Biz::Org::Source.3 Bric::Biz::OutputChannel.3 \
		Bric::Biz::OutputChannel::Element.3 Bric::Biz::Person.3 \
		Bric::Biz::Person::User.3 Bric::Biz::Site.3 Bric::Biz::Workflow.3 \
		Bric::Biz::Workflow::Parts::Desk.3 Bric::Changes.3 Bric::Config.3 \
		Bric::DBA.3 Bric::Dist::Action.3 Bric::Dist::Action::Akamaize.3 \
		Bric::Dist::Action::DTDValidate.3 Bric::Dist::Action::Email.3 \
		Bric::Dist::Action::HTMLClean.3 Bric::Dist::Action::Mover.3 \
		Bric::Dist::ActionType.3 Bric::Dist::Client.3 Bric::Dist::Handler.3 \
		Bric::Dist::Resource.3 Bric::Dist::Server.3 Bric::Dist::ServerType.3 \
		Bric::ElementAdmin.3 Bric::FAQ.3 Bric::HTMLTemplate.3 Bric::Hacker.3 \
		Bric::License.3 Bric::SOAP.3 Bric::SOAP::Asset.3 Bric::SOAP::Auth.3 \
		Bric::SOAP::Category.3 Bric::SOAP::Desk.3 Bric::SOAP::Element.3 \
		Bric::SOAP::Handler.3 Bric::SOAP::Keyword.3 Bric::SOAP::Media.3 \
		Bric::SOAP::MediaType.3 Bric::SOAP::Site.3 Bric::SOAP::Story.3 \
		Bric::SOAP::Template.3 Bric::SOAP::User.3 Bric::SOAP::Util.3 \
		Bric::SOAP::Workflow.3 Bric::Security.3 Bric::Templates.3 Bric::ToDo.3 \
		Bric::Util::Alert.3 Bric::Util::AlertType.3 \
		Bric::Util::AlertType::Parts::Rule.3 Bric::Util::Alerted.3 \
		Bric::Util::Alerted::Parts::Sent.3 Bric::Util::Async.3 \
		Bric::Util::Attribute.3 Bric::Util::Attribute::Action.3 \
		Bric::Util::Attribute::AssetType.3 Bric::Util::Attribute::AssetTypeData.3 \
		Bric::Util::Attribute::Category.3 Bric::Util::Attribute::Formatting.3 \
		Bric::Util::Attribute::Grp.3 Bric::Util::Attribute::Media.3 \
		Bric::Util::Attribute::MediaDataTile.3 Bric::Util::Attribute::Member.3 \
		Bric::Util::Attribute::Person.3 Bric::Util::Attribute::Story.3 \
		Bric::Util::Attribute::StoryDataTile.3 Bric::Util::Attribute::Workspace.3 \
		Bric::Util::Burner.3 Bric::Util::Burner::Mason.3 \
		Bric::Util::Burner::Template.3 Bric::Util::Burner::TemplateToolkit.3 \
		Bric::Util::CharTrans.3 Bric::Util::Class.3 Bric::Util::Coll.3 \
		Bric::Util::Coll::Action.3 Bric::Util::Coll::Addr.3 \
		Bric::Util::Coll::Addr::Person.3 Bric::Util::Coll::Contact.3 \
		Bric::Util::Coll::Keyword.3 Bric::Util::Coll::Member.3 \
		Bric::Util::Coll::OCElement.3 Bric::Util::Coll::OCInclude.3 \
		Bric::Util::Coll::OutputChannel.3 Bric::Util::Coll::Priv.3 \
		Bric::Util::Coll::Resource.3 Bric::Util::Coll::Rule.3 \
		Bric::Util::Coll::Server.3 Bric::Util::Coll::ServerType.3 \
		Bric::Util::Coll::Site.3 Bric::Util::DBD::Oracle.3 Bric::Util::DBD::Pg.3 \
		Bric::Util::DBD::mysql.3 Bric::Util::DBI.3 Bric::Util::Event.3 \
		Bric::Util::EventType.3 Bric::Util::FTP::DirHandle.3 \
		Bric::Util::FTP::FileHandle.3 Bric::Util::FTP::Server.3 \
		Bric::Util::Fault.3 Bric::Util::Fault::Exception.3 \
		Bric::Util::Fault::Exception::AP.3 Bric::Util::Fault::Exception::DA.3 \
		Bric::Util::Fault::Exception::DP.3 Bric::Util::Fault::Exception::GEN.3 \
		Bric::Util::Fault::Exception::MNI.3 Bric::Util::Grp.3 \
		Bric::Util::Grp::AlertType.3 Bric::Util::Grp::Asset.3 \
		Bric::Util::Grp::AssetLanguage.3 Bric::Util::Grp::AssetType.3 \
		Bric::Util::Grp::AssetVersion.3 Bric::Util::Grp::CategorySet.3 \
		Bric::Util::Grp::ContribType.3 Bric::Util::Grp::Desk.3 \
		Bric::Util::Grp::Dest.3 Bric::Util::Grp::Element.3 \
		Bric::Util::Grp::ElementType.3 Bric::Util::Grp::Event.3 \
		Bric::Util::Grp::Formatting.3 Bric::Util::Grp::Grp.3 \
		Bric::Util::Grp::Job.3 Bric::Util::Grp::Keyword.3 \
		Bric::Util::Grp::Media.3 Bric::Util::Grp::MediaType.3 \
		Bric::Util::Grp::Org.3 Bric::Util::Grp::OutputChannel.3 \
		Bric::Util::Grp::Parts::Member.3 \
		Bric::Util::Grp::Parts::Member::Contrib.3 Bric::Util::Grp::Person.3 \
		Bric::Util::Grp::Pref.3 Bric::Util::Grp::Site.3 Bric::Util::Grp::Source.3 \
		Bric::Util::Grp::Story.3 Bric::Util::Grp::User.3 \
		Bric::Util::Grp::Workflow.3 Bric::Util::Job.3 Bric::Util::Job::Dist.3 \
		Bric::Util::Job::Pub.3 Bric::Util::Language.3 Bric::Util::Language::bo.3 \
		Bric::Util::Language::de_de.3 Bric::Util::Language::en_us.3 \
		Bric::Util::Language::it_it.3 Bric::Util::Language::km.3 \
		Bric::Util::Language::ko_ko.3 Bric::Util::Language::lo.3 \
		Bric::Util::Language::my.3 Bric::Util::Language::pt_pt.3 \
		Bric::Util::Language::ug.3 Bric::Util::Language::vi_vn.3 \
		Bric::Util::Language::zh_cn.3 Bric::Util::Language::zh_hk.3 \
		Bric::Util::Language::zh_tw.3 Bric::Util::MediaType.3 \
		Bric::Util::Pref.3 Bric::Util::Priv.3 Bric::Util::Priv::Parts::Const.3 \
		Bric::Util::Time.3 Bric::Util::Trans::FS.3 Bric::Util::Trans::FTP.3 \
		Bric::Util::Trans::Jabber.3 Bric::Util::Trans::Mail.3 \
		Bric::Util::Trans::SFTP.3 Bric::Util::Trans::WebDAV.3 \
		Bric::Util::UserPref.3 Bric::Util::WebDav.3

SQLDIR=		${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

# Setup for $PREFIX
post-patch:
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${REINPLACE_CMD} -e "s,%%SQLDIR%%,${SQLDIR},g" ${WRKSRC}/bin/bric_pgimport
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%SITE_PERL_REL%%,${SITE_PERL_REL},g" \
		-e "s,%%MAN3PREFIX%%,${MAN3PREFIX},g" \
		-e "s,%%MAN1PREFIX%%,${MAN1PREFIX},g" ${WRKSRC}/inst/config.pl

# Install SQL file and display pkg-message
post-install:
	@${MKDIR} ${SQLDIR}
	${INSTALL_DATA} ${WRKSRC}/inst/Pg.sql ${SQLDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
