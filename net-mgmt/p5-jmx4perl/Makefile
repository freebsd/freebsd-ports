# $FreeBSD$

PORTNAME=	jmx4perl
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RO/ROLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	JMX access for Perl

RUN_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Carp>=0:${PORTSDIR}/devel/p5-Carp \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-Crypt-Blowfish_PP>=0:${PORTSDIR}/security/p5-Crypt-Blowfish_PP \
		p5-Crypt-OpenPGP>=0:${PORTSDIR}/security/p5-Crypt-OpenPGP \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-File-SearchPath>=0:${PORTSDIR}/devel/p5-File-SearchPath \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Module-Find>=0:${PORTSDIR}/devel/p5-Module-Find \
		p5-Nagios-Plugin>=0:${PORTSDIR}/net-mgmt/p5-Nagios-Plugin \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Sys-SigAction>=0:${PORTSDIR}/devel/p5-Sys-SigAction \
		p5-Term-Clui>=0:${PORTSDIR}/devel/p5-Term-Clui \
		p5-Term-ProgressBar>=0:${PORTSDIR}/devel/p5-Term-ProgressBar \
		p5-Term-ShellUI>=0:${PORTSDIR}/shells/p5-Term-ShellUI \
		p5-Term-Size>=0:${PORTSDIR}/devel/p5-Term-Size \
		p5-Text-ParseWords>=0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN1 =	cacti_jmx4perl.1 \
	check_jmx4perl.1 \
	j4psh.1 \
	jmx4perl.1 \
	jolokia.1

MAN3=	JMX::Jmx4Perl.3 \
	JMX::Jmx4Perl::Agent.3 \
	JMX::Jmx4Perl::Agent::Jolokia::ArtifactHandler.3 \
	JMX::Jmx4Perl::Agent::Jolokia::DownloadAgent.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Logger.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Meta.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Verifier.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Verifier::ChecksumVerifier.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Verifier::GnuPGVerifier.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Verifier::MD5Verifier.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Verifier::OpenPGPVerifier.3 \
	JMX::Jmx4Perl::Agent::Jolokia::Verifier::SHA1Verifier.3 \
	JMX::Jmx4Perl::Agent::Jolokia::WebXmlHandler.3 \
	JMX::Jmx4Perl::Agent::UserAgent.3 \
	JMX::Jmx4Perl::Alias.3 \
	JMX::Jmx4Perl::Alias::Object.3 \
	JMX::Jmx4Perl::Config.3 \
	JMX::Jmx4Perl::J4psh.3 \
	JMX::Jmx4Perl::J4psh::Command.3 \
	JMX::Jmx4Perl::J4psh::Command::Global.3 \
	JMX::Jmx4Perl::J4psh::Command::MBean.3 \
	JMX::Jmx4Perl::J4psh::Command::Server.3 \
	JMX::Jmx4Perl::J4psh::CommandHandler.3 \
	JMX::Jmx4Perl::J4psh::CompletionHandler.3 \
	JMX::Jmx4Perl::J4psh::ServerHandler.3 \
	JMX::Jmx4Perl::J4psh::Shell.3 \
	JMX::Jmx4Perl::Manual.3 \
	JMX::Jmx4Perl::Nagios::CactiJmx4Perl.3 \
	JMX::Jmx4Perl::Nagios::CheckJmx4Perl.3 \
	JMX::Jmx4Perl::Nagios::SingleCheck.3 \
	JMX::Jmx4Perl::Product::ActiveMQ.3 \
	JMX::Jmx4Perl::Product::BaseHandler.3 \
	JMX::Jmx4Perl::Product::Geronimo.3 \
	JMX::Jmx4Perl::Product::Glassfish.3 \
	JMX::Jmx4Perl::Product::Hadoop.3 \
	JMX::Jmx4Perl::Product::JBoss.3 \
	JMX::Jmx4Perl::Product::Jetty.3 \
	JMX::Jmx4Perl::Product::Jonas.3 \
	JMX::Jmx4Perl::Product::Resin.3 \
	JMX::Jmx4Perl::Product::SpringDM.3 \
	JMX::Jmx4Perl::Product::Terracotta.3 \
	JMX::Jmx4Perl::Product::Tomcat.3 \
	JMX::Jmx4Perl::Product::Unknown.3 \
	JMX::Jmx4Perl::Product::Weblogic.3 \
	JMX::Jmx4Perl::Product::Websphere.3 \
	JMX::Jmx4Perl::Request.3 \
	JMX::Jmx4Perl::Response.3 \
	JMX::Jmx4Perl::Util.3

ETC_FILES=	common.cfg \
		glassfish.cfg \
		jboss.cfg \
		jetty.cfg \
		memory.cfg \
		metrics.cfg \
		threads.cfg \
		tomcat.cfg \
		weblogic.cfg

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	ETC_FILES="${ETC_FILES}"

post-install:
	@${MKDIR} ${ETCDIR}
.for f in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${ETCDIR}/${f}.sample
.endfor

.include <bsd.port.mk>
