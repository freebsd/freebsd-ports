# New ports collection makefile for:	p5-XML-Stream
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	XML-Stream
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML::Stream provides you with access to XML Stream

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		XML::Stream.3 XML::Stream::Namespace.3 XML::Stream::Node.3 \
		XML::Stream::Parser.3 XML::Stream::Parser::DTD.3 \
		XML::Stream::Tree.3 \
		XML::Stream::IO::Select::Win32.3

.include <bsd.port.mk>
