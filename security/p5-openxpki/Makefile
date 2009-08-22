# New ports collection makefile for:	p5-openxpki
# Date created:				29 Sep 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki
PORTVERSION=	0.9.1389
CATEGORIES=	security perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9.1300
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl based trustcenter software for PKI: core for server

BUILD_DEPENDS=	\
	p5-Workflow>=0.31:${PORTSDIR}/devel/p5-Workflow \
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
	${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
	${SITE_PERL}/Class/Std.pm:${PORTSDIR}/devel/p5-Class-Std \
	${SITE_PERL}/Mail/RFC822/Address.pm:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
	${SITE_PERL}/${PERL_ARCH}/Proc/ProcessTable.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable \
	${SITE_PERL}/Sys/SigAction.pm:${PORTSDIR}/devel/p5-Sys-SigAction \
	${SITE_PERL}/Data/Password.pm:${PORTSDIR}/security/p5-Data-Password \
	${SITE_PERL}/RT/Client/REST.pm:${PORTSDIR}/www/p5-RT-Client-REST \
	${SITE_PERL}/Data/Serializer.pm:${PORTSDIR}/devel/p5-Data-Serializer \
	${SITE_PERL}/${PERL_ARCH}/IPC/ShareLite.pm:${PORTSDIR}/devel/p5-IPC-ShareLite \
	${SITE_PERL}/DateTime/Format/DateParse.pm:${PORTSDIR}/devel/p5-DateTime-Format-DateParse \
	${SITE_PERL}/IO/Prompt.pm:${PORTSDIR}/devel/p5-IO-Prompt
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	OpenXPKI.3 \
	OpenXPKI::Crypto::API.3 \
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
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::GOST2001.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::GOST2001CP.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::GOST94.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::GOST94CP.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_key::RSA.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_pkcs10.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_pkcs12.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::create_random.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::get_pkcs8_keytype.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::is_issuer.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::is_prime.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::issue_cert.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::issue_crl.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::list_algorithms.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_decrypt.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_encrypt.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_get_chain.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_sign.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Command::pkcs7_verify.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Config.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::GOST.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::OpenSSL.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::PKCS11.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::Engine::nCipher.3 \
	OpenXPKI::Crypto::Backend::OpenSSL::XS.3 \
	OpenXPKI::Crypto::CLI.3 \
	OpenXPKI::Crypto::CRL.3 \
	OpenXPKI::Crypto::CRR.3 \
	OpenXPKI::Crypto::CSR.3 \
	OpenXPKI::Crypto::Header.3 \
	OpenXPKI::Crypto::Object.3 \
	OpenXPKI::Crypto::PKCS7.3 \
	OpenXPKI::Crypto::Profile::Base.3 \
	OpenXPKI::Crypto::Profile::CRL.3 \
	OpenXPKI::Crypto::Profile::Certificate.3 \
	OpenXPKI::Crypto::Secret.3 \
	OpenXPKI::Crypto::Secret::Plain.3 \
	OpenXPKI::Crypto::Secret::Split.3 \
	OpenXPKI::Crypto::TokenManager.3 \
	OpenXPKI::Crypto::Tool::CreateJavaKeystore.3 \
	OpenXPKI::Crypto::Tool::CreateJavaKeystore::API.3 \
	OpenXPKI::Crypto::Tool::CreateJavaKeystore::CLI.3 \
	OpenXPKI::Crypto::Tool::CreateJavaKeystore::Command::create_keystore.3 \
	OpenXPKI::Crypto::Tool::CreateJavaKeystore::Engine::OpenSSL.3 \
	OpenXPKI::Crypto::Tool::PKCS7.3 \
	OpenXPKI::Crypto::Tool::PKCS7::API.3 \
	OpenXPKI::Crypto::Tool::PKCS7::CLI.3 \
	OpenXPKI::Crypto::Tool::PKCS7::Command::get_subject.3 \
	OpenXPKI::Crypto::Tool::PKCS7::Command::is_not_self_signed.3 \
	OpenXPKI::Crypto::Tool::PKCS7::Command::verify.3 \
	OpenXPKI::Crypto::Tool::PKCS7::Engine::OpenSSL.3 \
	OpenXPKI::Crypto::Tool::SCEP.3 \
	OpenXPKI::Crypto::Tool::SCEP::API.3 \
	OpenXPKI::Crypto::Tool::SCEP::CLI.3 \
	OpenXPKI::Crypto::Tool::SCEP::Command::create_certificate_reply.3 \
	OpenXPKI::Crypto::Tool::SCEP::Command::create_error_reply.3 \
	OpenXPKI::Crypto::Tool::SCEP::Command::create_pending_reply.3 \
	OpenXPKI::Crypto::Tool::SCEP::Command::get_message_type.3 \
	OpenXPKI::Crypto::Tool::SCEP::Command::get_pkcs10.3 \
	OpenXPKI::Crypto::Tool::SCEP::Command::get_signer_cert.3 \
	OpenXPKI::Crypto::Tool::SCEP::Command::get_transaction_id.3 \
	OpenXPKI::Crypto::Tool::SCEP::Engine::OpenSSL.3 \
	OpenXPKI::Crypto::Toolkit.3 \
	OpenXPKI::Crypto::VolatileVault.3 \
	OpenXPKI::Crypto::X509.3 \
	OpenXPKI::DN.3 \
	OpenXPKI::DateTime.3 \
	OpenXPKI::Debug.3 \
	OpenXPKI::Exception.3 \
	OpenXPKI::FileUtils.3 \
	OpenXPKI::LdapUtils.3 \
	OpenXPKI::Serialization::Fast.3 \
	OpenXPKI::Serialization::JSON.3 \
	OpenXPKI::Serialization::Simple.3 \
	OpenXPKI::Server.3 \
	OpenXPKI::Server::ACL.3 \
	OpenXPKI::Server::API.3 \
	OpenXPKI::Server::API::Default.3 \
	OpenXPKI::Server::API::Object.3 \
	OpenXPKI::Server::API::Secret.3 \
	OpenXPKI::Server::API::Visualization.3 \
	OpenXPKI::Server::API::Workflow.3 \
	OpenXPKI::Server::Authentication.3 \
	OpenXPKI::Server::Authentication::Anonymous.3 \
	OpenXPKI::Server::Authentication::ClientSSO.3 \
	OpenXPKI::Server::Authentication::ClientX509.3 \
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
	OpenXPKI::Server::DBI::Driver::Oracle.3 \
	OpenXPKI::Server::DBI::Driver::PostgreSQL.3 \
	OpenXPKI::Server::DBI::Driver::SQLite.3 \
	OpenXPKI::Server::DBI::Hash.3 \
	OpenXPKI::Server::DBI::SQL.3 \
	OpenXPKI::Server::DBI::Schema.3 \
	OpenXPKI::Server::Init.3 \
	OpenXPKI::Server::Log.3 \
	OpenXPKI::Server::Log::Appender::DBI.3 \
	OpenXPKI::Server::Log::NOOP.3 \
	OpenXPKI::Server::Notification.3 \
	OpenXPKI::Server::Notification::Dispatcher.3 \
	OpenXPKI::Server::Notification::RT.3 \
	OpenXPKI::Server::Session.3 \
	OpenXPKI::Server::Session::Mock.3 \
	OpenXPKI::Server::Workflow.3 \
	OpenXPKI::Server::Workflow::Activity.3 \
	OpenXPKI::Server::Workflow::Activity::CRLIssuance::DetermineNextCA.3 \
	OpenXPKI::Server::Workflow::Activity::CRLIssuance::GetCRLProfile.3 \
	OpenXPKI::Server::Workflow::Activity::CRLIssuance::IssueCRL.3 \
	OpenXPKI::Server::Workflow::Activity::CRLIssuance::PublishCRL.3 \
	OpenXPKI::Server::Workflow::Activity::CRR::PersistRequest.3 \
	OpenXPKI::Server::Workflow::Activity::CSR::ChangeNotBeforeOrAfter.3 \
	OpenXPKI::Server::Workflow::Activity::CSR::GenerateKey.3 \
	OpenXPKI::Server::Workflow::Activity::CSR::GeneratePKCS10.3 \
	OpenXPKI::Server::Workflow::Activity::CSR::PersistRequest.3 \
	OpenXPKI::Server::Workflow::Activity::CertIssuance::GetCertProfile.3 \
	OpenXPKI::Server::Workflow::Activity::CertIssuance::ImportCertData.3 \
	OpenXPKI::Server::Workflow::Activity::CertIssuance::Issue.3 \
	OpenXPKI::Server::Workflow::Activity::CertIssuance::PersistCertificate.3 \
	OpenXPKI::Server::Workflow::Activity::CertLdapPublish::AddMissingNode.3 \
	OpenXPKI::Server::Workflow::Activity::CertLdapPublish::ImportPublicData.3 \
	OpenXPKI::Server::Workflow::Activity::CertLdapPublish::PublicCertLdap.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::Cleanup.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::ExportLogs.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::ExportWorkflowInstances.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::ImportLogs.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::ImportWorkflowInstances.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::PackArchive.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::PrepareEnv.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::ReadArchive.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::UnpackArchive.3 \
	OpenXPKI::Server::Workflow::Activity::DataExchange::WriteArchive.3 \
	OpenXPKI::Server::Workflow::Activity::PasswordSafe::RetrievePassword.3 \
	OpenXPKI::Server::Workflow::Activity::PasswordSafe::StorePassword.3 \
	OpenXPKI::Server::Workflow::Activity::SCEP::ExtractCSR.3 \
	OpenXPKI::Server::Workflow::Activity::SCEP::SetContextFromCSR.3 \
	OpenXPKI::Server::Workflow::Activity::SCEP::SetContextFromOriginalCert.3 \
	OpenXPKI::Server::Workflow::Activity::Skeleton.3 \
	OpenXPKI::Server::Workflow::Activity::SmartCard::CreateServerCSR.3 \
	OpenXPKI::Server::Workflow::Activity::SmartCard::ForkWorkflowInstances.3 \
	OpenXPKI::Server::Workflow::Activity::SmartCard::GetLDAPData.3 \
	OpenXPKI::Server::Workflow::Activity::SmartCard::PersistCSRs.3 \
	OpenXPKI::Server::Workflow::Activity::SmartCard::PublishCertificates.3 \
	OpenXPKI::Server::Workflow::Activity::SmartCard::WriteCertificateToInstall.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::Approve.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::CancelApprovals.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::DetermineIssuingCA.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::Export.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::ForkWorkflowInstance.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::Notification.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::NotifyParentWorkflow.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::SetErrorCode.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::SetSource.3 \
	OpenXPKI::Server::Workflow::Activity::Tools::Sleep.3 \
	OpenXPKI::Server::Workflow::Condition::ACL.3 \
	OpenXPKI::Server::Workflow::Condition::AlwaysFalse.3 \
	OpenXPKI::Server::Workflow::Condition::AlwaysTrue.3 \
	OpenXPKI::Server::Workflow::Condition::Approved.3 \
	OpenXPKI::Server::Workflow::Condition::CRLSigningCAsLeft.3 \
	OpenXPKI::Server::Workflow::Condition::CertificateNotYetRevoked.3 \
	OpenXPKI::Server::Workflow::Condition::CheckCertTestResult.3 \
	OpenXPKI::Server::Workflow::Condition::CheckForkedWorkflowChildren.3 \
	OpenXPKI::Server::Workflow::Condition::CorrectNumberOfValidCerts.3 \
	OpenXPKI::Server::Workflow::Condition::CorrectTiming.3 \
	OpenXPKI::Server::Workflow::Condition::InitialEnrollmentOrRenewal.3 \
	OpenXPKI::Server::Workflow::Condition::IsCertificateIssuancePossible.3 \
	OpenXPKI::Server::Workflow::Condition::IsServerKeyGeneration.3 \
	OpenXPKI::Server::Workflow::Condition::IsValidSignatureWithRequestedDN.3 \
	OpenXPKI::Server::Workflow::Condition::Key.3 \
	OpenXPKI::Server::Workflow::Condition::LdapDnAvailable.3 \
	OpenXPKI::Server::Workflow::Condition::MoreCSRsToCreate.3 \
	OpenXPKI::Server::Workflow::Condition::MoreCertsToTest.3 \
	OpenXPKI::Server::Workflow::Condition::Server.3 \
	OpenXPKI::Server::Workflow::Condition::SignedUsingOriginalCertOrSelfSigned.3 \
	OpenXPKI::Server::Workflow::Condition::UseLdap.3 \
	OpenXPKI::Server::Workflow::Condition::ValidCSRSerialPresent.3 \
	OpenXPKI::Server::Workflow::Condition::WorkflowChildrenFailure.3 \
	OpenXPKI::Server::Workflow::Condition::WorkflowChildrenSuccessfullyFinished.3 \
	OpenXPKI::Server::Workflow::Condition::WorkflowCreator.3 \
	OpenXPKI::Server::Workflow::Observer::Debug.3 \
	OpenXPKI::Server::Workflow::Observer::Log.3 \
	OpenXPKI::Server::Workflow::Persister::DBI.3 \
	OpenXPKI::Server::Workflow::Persister::DBI::SequenceId.3 \
	OpenXPKI::Server::Workflow::Validator::ApprovalSignature.3 \
	OpenXPKI::Server::Workflow::Validator::Bulk.3 \
	OpenXPKI::Server::Workflow::Validator::CertProfile.3 \
	OpenXPKI::Server::Workflow::Validator::CertRole.3 \
	OpenXPKI::Server::Workflow::Validator::CertSubject.3 \
	OpenXPKI::Server::Workflow::Validator::CertSubjectAltName.3 \
	OpenXPKI::Server::Workflow::Validator::CertSubjectAltNameParts.3 \
	OpenXPKI::Server::Workflow::Validator::CertSubjectParts.3 \
	OpenXPKI::Server::Workflow::Validator::Creator.3 \
	OpenXPKI::Server::Workflow::Validator::InvalidityTime.3 \
	OpenXPKI::Server::Workflow::Validator::KeyLength.3 \
	OpenXPKI::Server::Workflow::Validator::KeyReuse.3 \
	OpenXPKI::Server::Workflow::Validator::PKCS10.3 \
	OpenXPKI::Server::Workflow::Validator::PasswordQuality.3 \
	OpenXPKI::Server::Workflow::Validator::ReasonCode.3 \
	OpenXPKI::Server::Workflow::Validator::SPKAC.3 \
	OpenXPKI::Server::Workflow::Validator::UnusedID.3 \
	OpenXPKI::Server::Workflow::Validator::ValidityTime.3 \
	OpenXPKI::Service.3 \
	OpenXPKI::Service::Default.3 \
	OpenXPKI::Service::Default::Command.3 \
	OpenXPKI::Service::Default::Command::nop.3 \
	OpenXPKI::Service::SCEP.3 \
	OpenXPKI::Service::SCEP::Command.3 \
	OpenXPKI::Service::SCEP::Command::GetCACert.3 \
	OpenXPKI::Service::SCEP::Command::PKIOperation.3 \
	OpenXPKI::Template::Plugin::RandomPassword.3 \
	OpenXPKI::Tests.3 \
	OpenXPKI::Transport::Simple.3 \
	OpenXPKI::VERSION.3 \
	OpenXPKI::Workflow::Factory.3 \
	OpenXPKI::XML::Cache.3 \
	OpenXPKI::XML::Config.3 \
	OpenXPKI::i18n.3
USE_GMAKE=	yes
USE_OPENSSL=	yes
PERL_CONFIGURE=	5.8.6+

OPTIONS=	DEVELOPER	"Install development tools for OpenXPKI?" off \
		GRAPHVIZ	"With graphical visualization of workflows?" off
# If DEVELOPER is checked, then docbook, Java and Xorg libraries are installed.
# They are needed only if you plan to fetch development svn snapshot,
# then edit XML prototypes for collection of OpenXPKI guides, and then
# compile the collection into HTML or PDF forms.
# If you want to read OpenXPKI documentation, these tools are not needed.
# Just visit http://www.openxpki.org/docs/

.include <bsd.port.options.mk>

# needs openssl 0.9.8
.if ${OSVERSION} < 700019
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DEVELOPER)
RUN_DEPENDS+=	fop:${PORTSDIR}/textproc/fop \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/java/jai/lib/libmlib_jai.so:${PORTSDIR}/java/jai
.endif
.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
.endif

post-install:
	${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.post.mk>
