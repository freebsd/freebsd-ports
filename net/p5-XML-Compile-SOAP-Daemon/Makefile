# New ports collection makefile for:	net/p5-XML-Compile-SOAP-Daemon
# Date created:				15 April 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile-SOAP-Daemon
PORTVERSION=	3.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for SOAP message servers

BUILD_DEPENDS=	p5-Log-Report>=0.90:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile-Cache>=0.99.1:${PORTSDIR}/textproc/p5-XML-Compile-Cache \
		p5-XML-Compile-SOAP-WSA>=0.12:${PORTSDIR}/net/p5-XML-Compile-SOAP-WSA \
		p5-XML-Compile-SOAP>=2.26:${PORTSDIR}/net/p5-XML-Compile-SOAP \
		p5-XML-Compile>=1.24:${PORTSDIR}/textproc/p5-XML-Compile
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>0:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=	XML::Compile::SOAP::Daemon.3 \
	XML::Compile::SOAP::Daemon::AnyDaemon.3 \
	XML::Compile::SOAP::Daemon::CGI.3 \
	XML::Compile::SOAP::Daemon::LWPutil.3 \
	XML::Compile::SOAP::Daemon::NetServer.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::|::Tester/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
