PORTNAME=	SOAP-Amazon-S3
DISTVERSION=	0.0401
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KARJALA/Amazon
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for interfacing with Amazon S3 through SOAP
WWW=		https://metacpan.org/release/KARJALA/SOAP-Amazon-S3-0.0401

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-SOAP-MySOAP>=0:net/p5-SOAP-MySOAP \
		p5-XML-MyXML>=0:textproc/p5-XML-MyXML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
