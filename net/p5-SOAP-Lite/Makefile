# New ports collection makefile for:	p5-SOAP-Lite
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	SOAP-Lite
PORTVERSION=	0.55
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SOAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--noprompt
INSTALL_TARGET=	pure_install

MAN1=		SOAPsh.pl.1 XMLRPCsh.pl.1
MAN3PREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}
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

.include <bsd.port.mk>
