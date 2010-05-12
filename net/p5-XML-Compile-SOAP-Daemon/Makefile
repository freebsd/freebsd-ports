# New ports collection makefile for:	net/p5-XML-Compile-SOAP-Daemon
# Date created:				15 April 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile-SOAP-Daemon
PORTVERSION=	2.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Base class for SOAP message servers

BUILD_DEPENDS=	p5-Net-Server>=0.97:${PORTSDIR}/net/p5-Net-Server \
		p5-libwww>=5.803:${PORTSDIR}/www/p5-libwww \
		p5-Log-Report>=0.22:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile-SOAP>=2.10:${PORTSDIR}/net/p5-XML-Compile-SOAP \
		p5-XML-Compile>=1.01:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.91:${PORTSDIR}/textproc/p5-XML-Compile-Cache
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Compile::SOAP::Daemon.3 \
	XML::Compile::SOAP::HTTPDaemon.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::|::Tester/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
