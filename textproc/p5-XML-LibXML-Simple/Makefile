# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	XML-LibXML-Simple
PORTVERSION=	0.93
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	XML::LibXML clone of XML::Simple::XMLin()

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-XML-LibXML>=1.64:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::LibXML::Simple.3

NO_STAGE=	yes
.include <bsd.port.mk>
