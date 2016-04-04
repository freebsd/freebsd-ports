# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	XML-LibXML-Simple
PORTVERSION=	0.95
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	XML::LibXML clone of XML::Simple::XMLin()

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Slurp-Tiny>=0:devel/p5-File-Slurp-Tiny \
		p5-XML-LibXML>=1.64:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
