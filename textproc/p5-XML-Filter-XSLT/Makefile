# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-Filter-XSLT
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XSLT as a SAX Filter

RUN_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-XML-LibXSLT>=0:${PORTSDIR}/textproc/p5-XML-LibXSLT
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::Filter::XSLT.3 XML::Filter::XSLT::LibXSLT.3

.include <bsd.port.mk>
