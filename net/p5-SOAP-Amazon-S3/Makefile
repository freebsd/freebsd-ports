# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	SOAP-Amazon-S3
PORTVERSION=	0.040.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for interfacing with Amazon S3 through SOAP

RUN_DEPENDS=	p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-SOAP-MySOAP>=0:${PORTSDIR}/net/p5-SOAP-MySOAP \
		p5-XML-MyXML>=0:${PORTSDIR}/textproc/p5-XML-MyXML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
