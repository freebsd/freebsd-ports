# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-WSDL
PORTVERSION=	0.061
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Create WSDL documents from (extended) pod

BUILD_DEPENDS=	p5-IO-stringy>=2.110:${PORTSDIR}/devel/p5-IO-stringy \
		p5-XML-Writer>=0.531:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-XPath>=1.13:${PORTSDIR}/textproc/p5-XML-XPath
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Pod::WSDL.3 \
	Pod::WSDL::AUTOLOAD.3 \
	Pod::WSDL::Attr.3 \
	Pod::WSDL::Doc.3 \
	Pod::WSDL::Fault.3 \
	Pod::WSDL::Method.3 \
	Pod::WSDL::Param.3 \
	Pod::WSDL::Return.3 \
	Pod::WSDL::Type.3 \
	Pod::WSDL::Utils.3 \
	Pod::WSDL::Writer.3

NO_STAGE=	yes
.include <bsd.port.mk>
