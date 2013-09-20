# Created by: vanilla
# $FreeBSD$

PORTNAME=	SOAP-Lite
PORTVERSION=	0.716
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SOAP::Lite - Client and server side SOAP implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-XML-Parser>=2.23:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cycle>=0:${PORTSDIR}/devel/p5-Devel-Cycle \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

CONFLICTS=	p5-SOAP-Lite-0.60* p5-SOAP-[0-9]*

CONFIGURE_ARGS=	--noprompt
INSTALL_TARGET=	pure_install
USE_PERL5=	configure
USES=		perl5 shebangfix

MAN1=		SOAPsh.pl.1 \
		XMLRPCsh.pl.1 \
		stubmaker.pl.1
MAN3=		Apache::SOAP.3 \
		Apache::XMLRPC::Lite.3 \
		SOAP::Client.3 \
		SOAP::Constants.3 \
		SOAP::Data.3 \
		SOAP::Deserializer.3 \
		SOAP::Fault.3 \
		SOAP::Header.3 \
		SOAP::Lite.3 \
		SOAP::Lite::Packager.3 \
		SOAP::Packager.3 \
		SOAP::SOM.3 \
		SOAP::Schema.3 \
		SOAP::Serializer.3 \
		SOAP::Server.3 \
		SOAP::Test.3 \
		SOAP::Trace.3 \
		SOAP::Transport.3 \
		SOAP::Transport::LOOPBACK.3 \
		SOAP::Transport::POP3.3 \
		SOAP::Utils.3 \
		UDDI::Lite.3 \
		XML::Parser::Lite.3 \
		XMLRPC::Lite.3 \
		XMLRPC::Test.3 \
		XMLRPC::Transport::HTTP.3 \
		XMLRPC::Transport::POP3.3 \
		XMLRPC::Transport::TCP.3

SHEBANG_FILES=	bin/* t/*.pl t/*.t
perl_OLD_CMD=	.*perl

NO_STAGE=	yes
.include <bsd.port.mk>
