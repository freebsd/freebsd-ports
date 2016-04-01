# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	WebService-Simple
PORTVERSION=	0.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Simple Interface To Web Services APIs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-ConfigHash>=0:devel/p5-Class-Data-ConfigHash \
		p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-Hash-MultiValue>=0:devel/p5-Hash-MultiValue \
		p5-JSON>=2.0:converters/p5-JSON \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-URI>=1.36:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-Feed>=0:textproc/p5-XML-Feed \
		p5-XML-Parser-Lite-Tree>=0:textproc/p5-XML-Parser-Lite-Tree

USE_PERL5=	modbuildtiny
USES=		perl5

.include <bsd.port.mk>
