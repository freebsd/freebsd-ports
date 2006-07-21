# New ports collection makefile for:	p5-openxpki
# Date created:				20 June 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki
PORTVERSION=	0.9.402
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	p5-
DISTFILES=	${SERVER} ${CLIENT} ${DEPLOYMENT} ${I18N}
DIST_SUBDIR=	${PORTNAME}

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

SERVER=		OpenXPKI-0.9.402.tar.gz
CLIENT=		OpenXPKI-Client-0.9.349.tar.gz \
		OpenXPKI-Client-SCEP-0.9.342.tar.gz \
		OpenXPKI-Client-SOAP-Lite-0.9.342.tar.gz \
		OpenXPKI-Client-CLI-0.9.389.tar.gz \
		OpenXPKI-Client-HTML-Mason-0.9.402.tar.gz
DEPLOYMENT=	openxpki-deployment-0.9.402.tar.gz
I18N=		openxpki-i18n-0.9.402.tar.gz
MAN1=	openxpki-configure.1 \
	openxpki-metaconf.1 \
	openxpkiadm.1 \
	openxpkictl.1
MAN3=	OpenXPKI.3 \
	OpenXPKI::Client.3 \
	OpenXPKI::Client::API.3 \
	OpenXPKI::Client::CLI.3 \
	OpenXPKI::Client::HTML::Mason.3 \
	OpenXPKI::Client::HTML::Mason::Javascript.3 \
	OpenXPKI::Client::HTML::Mason::Menu.3 \
	OpenXPKI::Client::SCEP.3 \
	OpenXPKI::Client::SOAP::Lite.3 \
	OpenXPKI::Crypto::Backend::API.3 \
	OpenXPKI::Crypto::Backend::OpenSSL.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::CLI.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_cert.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_crl.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_key.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::convert_pkcs10.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_cert.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::DSA.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::EC.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::GOST94.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::RSA.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_pkcs10.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_pkcs12.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_random.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::issue_cert.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::issue_crl.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_decrypt.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_encrypt.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_get_chain.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_sign.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_verify.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::symmetric_cipher.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Config.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::GOST.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::OpenSSL.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::nCipher.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::XS.3 \
	OpenXPKI::Crypto::CRL.3 \
	OpenXPKI::Crypto::CRR.3 \
	OpenXPKI::Crypto::CSR.3 \
	OpenXPKI::Crypto::Header.3 \
	OpenXPKI::Crypto::Object.3 \
	OpenXPKI::Crypto::PKCS7.3 \
	OpenXPKI::Crypto::Profile::Base.3 \
	OpenXPKI::Crypto::Profile::CRL.3 \
	OpenXPKI::Crypto::Profile::Certificate.3 \
	OpenXPKI::Crypto::TokenManager.3 \
	OpenXPKI::Crypto::VolatileVault.3 \
	OpenXPKI::Crypto::X509.3 \
	OpenXPKI::DN.3 \
	OpenXPKI::DateTime.3 \
	OpenXPKI::Debug.3 \
	OpenXPKI::Exception.3 \
	OpenXPKI::Serialization::JSON.3 \
	OpenXPKI::Serialization::Simple.3 \
	OpenXPKI::Server.3 \
	OpenXPKI::Server::ACL.3 \
	OpenXPKI::Server::API.3 \
	OpenXPKI::Server::Authentication.3 \
	OpenXPKI::Server::Authentication::Anonymous.3 \
	OpenXPKI::Server::Authentication::External.3 \
	OpenXPKI::Server::Authentication::LDAP.3 \
	OpenXPKI::Server::Authentication::Password.3 \
	OpenXPKI::Server::Authentication::X509.3 \
	OpenXPKI::Server::Context.3 \
	OpenXPKI::Server::DBI.3 \
	OpenXPKI::Server::DBI::DBH.3 \
	OpenXPKI::Server::DBI::Driver.3 \
	OpenXPKI::Server::DBI::Driver::DB2.3 \
	OpenXPKI::Server::DBI::Driver::MySQL.3 \
	OpenXPKI::Server::DBI::Driver::PostgreSQL.3 \
	OpenXPKI::Server::DBI::Driver::SQLite.3 \
	OpenXPKI::Server::DBI::Hash.3 \
	OpenXPKI::Server::DBI::Object.3 \
	OpenXPKI::Server::DBI::SQL.3 \
	OpenXPKI::Server::DBI::Schema.3 \
	OpenXPKI::Server::Init.3 \
	OpenXPKI::Server::Log.3 \
	OpenXPKI::Server::Log::Appender::DBI.3 \
	OpenXPKI::Server::Session.3 \
	OpenXPKI::Server::Session::Mock.3 \
	OpenXPKI::Server::Workflow.3 \
	OpenXPKI::Server::Workflow::Activity.3 \
	OpenXPKI::Server::Workflow::Activity::Certificate::Issue.3 \
	OpenXPKI::Server::Workflow::Activity::Key::Generate.3 \
	OpenXPKI::Server::Workflow::Activity::Passphrase::Generate.3 \
	OpenXPKI::Server::Workflow::Activity::Profile::Create.3 \
	OpenXPKI::Server::Workflow::Activity::Request::Certificate::DataOnly::Create.3 \
	OpenXPKI::Server::Workflow::Activity::Request::Certificate::PKCS10::Create.3 \
	OpenXPKI::Server::Workflow::Activity::Skeleton.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::DetermineIssuingCA.3 \
	OpenXPKI::Server::Workflow::Persister::DBI.3 \
	OpenXPKI::Server::Workflow::Persister::DBI::SequenceId.3 \
	OpenXPKI::Server::Workflow::Validator::CertProfile.3 \
	OpenXPKI::Server::Workflow::Validator::CertSubject.3 \
	OpenXPKI::Server::Workflow::Validator::CertSubjectAltName.3 \
	OpenXPKI::Server::Workflow::Validator::SPKAC.3 \
	OpenXPKI::Service.3 \
	OpenXPKI::Service::Default.3 \
	OpenXPKI::Service::Default::Command.3 \
	OpenXPKI::Service::Default::Command::nop.3 \
	OpenXPKI::Service::Test.3 \
	OpenXPKI::Transport::Simple.3 \
	OpenXPKI::VERSION.3 \
	OpenXPKI::XML::Cache.3 \
	OpenXPKI::XML::Config.3 \
	OpenXPKI::i18n.3
USE_PERL5=	yes
USE_GETTEXT=	yes
### We can not do WITHOUT_NLS. Internationalization is needed
### even to use English language.
USE_GMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BETA=	yes
PERL_DIRS=	${SERVER} ${CLIENT}
NO_PERL_DIRS=	${DEPLOYMENT} ${I18N}
MAKE_MAKER_ENV=	PREFIX=${PREFIX}
DESTDIR?=	/
CONFIGURE_ARGS=	--prefix ${PREFIX} --dest ${DESTDIR}
MAN1PREFIX=	${PREFIX}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ for dir in ${PERL_DIRS}; do \
		dir="`${ECHO} $${dir} | ${SED} -e 's/.tar.gz//'`"; \
		cd ${WRKDIR}/$${dir} && \
		${ECHO} "DIR= $${dir}" && ${PERL5} Makefile.PL ${MAKE_MAKER_ENV}; \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile; \
	done

do-build:
	@ for dir in ${PERL_DIRS}; do \
		dir="`${ECHO} $${dir} | ${SED} -e 's/.tar.gz//'`"; \
		cd ${WRKDIR}/$${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE}; \
	done

do-install:
	@ for dir in ${PERL_DIRS}; do \
		dir="`${ECHO} $${dir} | ${SED} -e 's/.tar.gz//'`"; \
		cd ${WRKDIR}/$${dir} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}; \
	done

post-install:
	${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@ for dir in ${NO_PERL_DIRS}; do \
		dir="`${ECHO} $${dir} | ${SED} -e 's/.tar.gz//'`"; \
		cd ${WRKDIR}/$${dir} && \
		${ECHO} "DIR= $${dir}" && \
		if [ -f ./${CONFIGURE_SCRIPT} ]; then \
			${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
		fi && \
		${SETENV} ${MAKE_ENV} ${GMAKE} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}; \
	done

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=	requires newer Perl, but you can install required old additional perl modules from CPAN instead
.endif

.include <bsd.port.post.mk>
