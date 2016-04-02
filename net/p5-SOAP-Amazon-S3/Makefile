# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	SOAP-Amazon-S3
PORTVERSION=	0.040.1
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for interfacing with Amazon S3 through SOAP

BUILD_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-SOAP-MySOAP>=0:net/p5-SOAP-MySOAP \
		p5-XML-MyXML>=0:textproc/p5-XML-MyXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
