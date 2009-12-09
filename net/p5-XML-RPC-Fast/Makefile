# New ports collection makefile for:	XML-RPC-Fast
# Whom:					gugu
# Date created:				08 December 2009
# $FreeBSD$
# Generated with App::Pm2Port . Do not edit directly, please

PORTNAME=	XML-RPC-Fast
PORTVERSION=	0.6
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Fast and modular implementation for an XML-RPC client and server

BUILD_DEPENDS=	p5-XML-Hash-LX>=0.05:${PORTSDIR}/textproc/p5-XML-Hash-LX \
		p5-XML-LibXML>=1.58:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.3+
MAN3=		XML::RPC::Enc.3 \
		XML::RPC::Enc::LibXML.3 \
		XML::RPC::Fast.3 \
		XML::RPC::UA.3 \
		XML::RPC::UA::AnyEvent.3 \
		XML::RPC::UA::AnyEventSync.3 \
		XML::RPC::UA::LWP.3

.include <bsd.port.mk>
