PORTNAME=	SOAP-Amazon-S3
PORTVERSION=	0.0401
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for interfacing with Amazon S3 through SOAP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-SOAP-MySOAP>=0:net/p5-SOAP-MySOAP \
		p5-XML-MyXML>=0:textproc/p5-XML-MyXML

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
