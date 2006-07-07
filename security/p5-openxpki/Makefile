# New ports collection makefile for:	p5-openxpki
# Date created:				20 June 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki
PORTVERSION=	0.9.342
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openxpki
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh@cryptocom.ru
COMMENT=	Perl based enterprise class trastcenter software for PKI

BUILD_DEPENDS=	\
	${SITE_PERL}/Workflow.pm:${PORTSDIR}/devel/p5-Workflow \
	${SITE_PERL}/CGI/Session.pm:${PORTSDIR}/www/p5-CGI-Session \
	${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
	${SITE_PERL}/Locale/Recode.pm:${PORTSDIR}/devel/p5-Locale-libintl \
	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
	${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
	${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
	${SITE_PERL}/XML/Filter/XInclude.pm:${PORTSDIR}/textproc/p5-XML-Filter-XInclude \
	${SITE_PERL}/XML/SAX/Writer.pm:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
	${SITE_PERL}/XML/Validator/Schema.pm:${PORTSDIR}/textproc/p5-XML-Validator-Schema \
	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
	${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
	${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
	${SITE_PERL}/Config/Std.pm:${PORTSDIR}/devel/p5-Config-Std \
	${SITE_PERL}/IO/Prompt.pm:${PORTSDIR}/devel/p5-IO-Prompt \
	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=	openxpki-configure.1 \
	openxpki-metaconf.1 \
	openxpkiadm.1 \
	openxpkictl.1

MAN3=	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key.3 \
	OpenXPKI::Server::Session.3 \
	OpenXPKI::Service::Default.3 \
	OpenXPKI::Server::DBI::Driver.3 \
	OpenXPKI::Server::Authentication::External.3 \
	OpenXPKI::Transport::Simple.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_pkcs10.3 \
	OpenXPKI::Server::DBI::Driver::DB2.3 \
	OpenXPKI::Server::Workflow::Activity.3 \
	OpenXPKI::Crypto::Profile::Base.3 \
	OpenXPKI::Service::Default::Command.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_sign.3 \
	OpenXPKI::Server::API.3 \
	OpenXPKI::Crypto::CRL.3 \
	OpenXPKI::Serialization::JSON.3 \
	OpenXPKI::Server::Workflow::Activity::Passphrase::Generate.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine.3 \
	OpenXPKI.3 \
	OpenXPKI::Server::DBI.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::nCipher.3 \
	OpenXPKI::Server::DBI::Driver::PostgreSQL.3 \
	OpenXPKI::XML::Config.3 \
	OpenXPKI::Server::ACL.3 \
	OpenXPKI::XML::Cache.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::DSA.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_cert.3 \
	OpenXPKI::Server::DBI::Hash.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Config.3 \
	OpenXPKI::Server::Init.3 \
	OpenXPKI::Crypto::CSR.3 \
	OpenXPKI::Server::DBI::Schema.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_pkcs12.3 \
	OpenXPKI::Crypto::Object.3 \
	OpenXPKI::Service::Default::Command::nop.3 \
	OpenXPKI::Server::Authentication::Anonymous.3 \
	OpenXPKI::Crypto::Profile::Certificate.3 \
	OpenXPKI::Crypto::Backend::API.3 \
	OpenXPKI::Server::Authentication::LDAP.3 \
	OpenXPKI::Exception.3 \
	OpenXPKI::Crypto::X509.3 \
	OpenXPKI::Server::DBI::Object.3 \
	OpenXPKI::Debug.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_get_chain.3 \
	OpenXPKI::VERSION.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_verify.3 \
	OpenXPKI::Server.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::GOST.3 \
	OpenXPKI::Server::Workflow::Persister::DBI.3 \
	OpenXPKI::Service.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::XS.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::DetermineIssuingCA.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command.3 \
	OpenXPKI::Crypto::Backend::OpenSSL.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::EC.3 \
	OpenXPKI::Server::Workflow::Activity::Skeleton.3 \
	OpenXPKI::Server::Workflow::Persister::DBI::SequenceId.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_decrypt.3 \
	OpenXPKI::Server::Workflow::Activity::Request::Certificate::PKCS10::Create.3 \
	OpenXPKI::Server::Log::Appender::DBI.3 \
	OpenXPKI::i18n.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_pkcs10.3 \
	OpenXPKI::Server::DBI::SQL.3 \
	OpenXPKI::Server::Workflow::Activity::Certificate::Issue.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_cert.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::RSA.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::issue_crl.3 \
	OpenXPKI::Server::DBI::DBH.3 \
	OpenXPKI::Server::DBI::Driver::MySQL.3 \
	OpenXPKI::Crypto::Profile::CRL.3 \
	OpenXPKI::Server::Workflow::Activity::Profile::Create.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::issue_cert.3 \
	OpenXPKI::Server::Log.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_key.3 \
	OpenXPKI::Server::Authentication::X509.3 \
	OpenXPKI::Server::Workflow::Activity::Key::Generate.3 \
	OpenXPKI::Server::Workflow::Activity::Request::Certificate::DataOnly::Create.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::OpenSSL.3 \
	OpenXPKI::Server::Authentication::Password.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::CLI.3 \
	OpenXPKI::Crypto::Header.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_crl.3 \
	OpenXPKI::Server::Workflow.3 \
	OpenXPKI::Service::Test.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_encrypt.3 \
	OpenXPKI::DN.3 \
	OpenXPKI::DateTime.3 \
	OpenXPKI::Crypto::TokenManager.3 \
	OpenXPKI::Crypto::CRR.3 \
	OpenXPKI::Crypto::PKCS7.3 \
	OpenXPKI::Server::Authentication.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::GOST94.3 \
	OpenXPKI::Server::DBI::Driver::SQLite.3 \
	OpenXPKI::Serialization::Simple.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_random.3 \
	OpenXPKI::Server::Context.3 \
	OpenXPKI::Client::API.3 \
	OpenXPKI::Client.3 \
	OpenXPKI::Client::CLI.3 \
	OpenXPKI::Client::SOAP::Lite.3 \
	OpenXPKI::Client::HTML::Mason.3 \
	OpenXPKI::Client::HTML::Mason::Config.3

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BETA=	yes

SERVER_DIRS=	perl-modules
CLIENT_DIRS=	clients/perl/OpenXPKI-Client \
		clients/perl/OpenXPKI-Client-CLI \
		clients/perl/OpenXPKI-Client-SOAP-Lite \
		clients/perl/OpenXPKI-Client-HTML-Mason

DEPLOYMENT_DIRS=deployment
PERL_DIRS=	${SERVER_DIRS} ${CLIENT_DIRS}
NO_PERL_DIRS=	${DEPLOYMENT_DIRS}
POST_DIRS=	${CLIENT_DIRS} ${DEPLOYMENT_DIRS}
MAKE_MAKER_ENV=	PREFIX=${PREFIX}
CONFIGURE_ARGS=	--prefix ${PREFIX}
MAN1PREFIX=	${PREFIX}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|admgroup:\( *\)root|admgroup:\1wheel|g' \
		${WRKSRC}/deployment/etc/templates/default/openxpki.conf.in
	@${REINPLACE_CMD} -e \
	's|CFG\( *\)=\( *\)openxpki-metaconf|CFG\1=\2bin/openxpki-metaconf|g' \
	${WRKSRC}/deployment/Makefile.in

do-configure:
	@ cd ${WRKSRC}/perl-modules && ${ECHO} "342" > revision
	@ for dir in ${PERL_DIRS}; do \
		cd ${WRKSRC}/$${dir} && \
		${ECHO} "DIR= $${dir}" && ${PERL} Makefile.PL ${MAKE_MAKER_ENV}; \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile; \
	done

do-build:
	@ for dir in ${PERL_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE}; \
	done

do-install:
	@ for dir in ${PERL_DIRS}; do \
		cd ${WRKSRC}/$${dir} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}; \
	done

post-install:
	${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@ for dir in ${NO_PERL_DIRS}; do \
		cd ${WRKSRC}/$${dir} && \
		${ECHO} "DIR= $${dir}" && \
		${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/docs/architecture/whitepapers/OpenXPKI-Architecture-Overview.pdf \
		${DOCSDIR}
	@${ECHO_MSG} "===>   Documents intstalled in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=	requires newer Perl, but you can install required old additional perl modules from CPAN instead
.endif

.include <bsd.port.post.mk>
