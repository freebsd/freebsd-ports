# New ports collection makefile for:	net/p5-XML-Compile-SOAP-Daemon
# Date created:				15 April 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile-SOAP-Daemon
PORTVERSION=	3.00
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Base class for SOAP message servers

RUN_DEPENDS=	p5-Log-Report>=0.90:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile-Cache>=0.98:${PORTSDIR}/textproc/p5-XML-Compile-Cache \
		p5-XML-Compile-SOAP-WSA>=0.12:${PORTSDIR}/net/p5-XML-Compile-SOAP-WSA \
		p5-XML-Compile-SOAP>=2.20:${PORTSDIR}/net/p5-XML-Compile-SOAP \
		p5-XML-Compile>=1.2:${PORTSDIR}/textproc/p5-XML-Compile
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Compile::SOAP::Daemon.3 \
	XML::Compile::SOAP::Daemon::CGI.3 \
	XML::Compile::SOAP::Daemon::LWPutil.3 \
	XML::Compile::SOAP::Daemon::NetServer.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::|::Tester/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
