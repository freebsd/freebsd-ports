# New ports collection makefile for:	p5-SOAP-Lite
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	SOAP-Lite
PORTVERSION=	0.711
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SOAP::Lite - Client and server side SOAP implementation

RUN_DEPENDS=	p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-XML-Parser>=2.23:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
BUILD_DEPENDS=	${RUN_DEPENDS}

CONFLICTS=	p5-SOAP-Lite-0.60* p5-SOAP-[0-9]*

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=--noprompt
INSTALL_TARGET=	pure_install

MAN1=		SOAPsh.pl.1 XMLRPCsh.pl.1 stubmaker.pl.1
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

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|^#!.*perl|#!${PERL}|' \
		${WRKSRC}/bin/* ${WRKSRC}/t/*.t ${WRKSRC}/t/*.pl

.include <bsd.port.mk>
