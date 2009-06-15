# New ports collection makefile for:	p5-WebService-Simple
# Date created:		2008-05-19
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	WebService-Simple
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Simple Interface To Web Services APIs

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-ConfigHash>=0:${PORTSDIR}/devel/p5-Class-Data-ConfigHash \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WebService::Simple::Response.3 \
		WebService::Simple::Parser.3 \
		WebService::Simple::Parser::XML::Lite.3 \
		WebService::Simple::Parser::XML::LibXML.3 \
		WebService::Simple::Parser::XML::Simple.3 \
		WebService::Simple::Parser::XML::Feed.3 \
		WebService::Simple.3 \
		WebService::Simple::Parser::JSON.3

.include <bsd.port.mk>
