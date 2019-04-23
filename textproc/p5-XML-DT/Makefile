# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	XML-DT
PORTVERSION=	0.69
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for down translation of XML to strings

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Simple>=0:www/p5-HTTP-Simple \
		p5-XML-DTDParser>=2.00:textproc/p5-XML-DTDParser \
		p5-XML-LibXML>=1.54:textproc/p5-XML-LibXML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
