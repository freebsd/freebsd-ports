# New ports collection makefile for:	p5-XML-Stream
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	XML-Stream
DISTVERSION=	1.23_06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAPATRICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML::Stream provides you with access to XML Stream

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL
TEST_DEPENDS=	p5-Test-Simple>=0.92:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		XML::Stream.3 \
		XML::Stream::IO::Select::Win32.3 \
		XML::Stream::Namespace.3 \
		XML::Stream::Node.3 \
		XML::Stream::Parser.3 \
		XML::Stream::Parser::DTD.3 \
		XML::Stream::Tree.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Module-Build>=0.3603:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
