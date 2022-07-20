PORTNAME=	XML-Compile-SOAP-WSA
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	papowell@astart.com
COMMENT=	SOAP message messages with WSA fields

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Server>=0.97:net/p5-Net-Server \
		p5-libwww>=5.803:www/p5-libwww \
		p5-Log-Report>=0.22:devel/p5-Log-Report \
		p5-XML-Compile-SOAP>=2.10:net/p5-XML-Compile-SOAP \
		p5-XML-Compile>=1.01:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.91:textproc/p5-XML-Compile-Cache

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
