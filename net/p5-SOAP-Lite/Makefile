# New ports collection makefile for:	p5-SOAP-Lite
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	SOAP-Lite
PORTVERSION=	0.60a
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SOAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua
COMMENT=	SOAP::Lite - Client and server side SOAP implementation

BUILD_DEPENDS=	${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-0.60
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--noprompt
INSTALL_TARGET=	pure_install
USE_REINPLACE=	yes

MAN1=		SOAPsh.pl.1 XMLRPCsh.pl.1
MAN3=		Apache::SOAP.3 \
		Apache::XMLRPC::Lite.3 \
		SOAP::Lite.3 \
		SOAP::Test.3 \
		SOAP::Transport::FTP.3 \
		SOAP::Transport::JABBER.3 \
		SOAP::Transport::HTTP.3 \
		SOAP::Transport::IO.3 \
		SOAP::Transport::LOCAL.3 \
		SOAP::Transport::MAILTO.3 \
		SOAP::Transport::MQ.3 \
		SOAP::Transport::POP3.3 \
		SOAP::Transport::TCP.3 \
		UDDI::Lite.3 \
		XML::Parser::Lite.3 \
		XMLRPC::Lite.3 \
		XMLRPC::Test.3 \
		XMLRPC::Transport::HTTP.3 \
		XMLRPC::Transport::POP3.3 \
		XMLRPC::Transport::TCP.3

post-patch:
	@${REINPLACE_CMD} -e 's|bin/env|usr/bin/env|' \
		${WRKSRC}/bin/* ${WRKSRC}/t/*

.include <bsd.port.mk>
