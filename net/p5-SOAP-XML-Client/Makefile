# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SOAP-XML-Client
PORTVERSION=	2.8
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple frame work for talking with web services

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp>0:${PORTSDIR}/devel/p5-Carp \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Encode>0:${PORTSDIR}/converters/p5-Encode \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-SOAP-Data-Builder>0:${PORTSDIR}/net/p5-SOAP-Data-Builder \
		p5-SOAP-Lite>0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
