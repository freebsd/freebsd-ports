# $FreeBSD$

PORTNAME=	Apache-Solr
PORTVERSION=	1.05
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	High level interface to the Solr server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON>=0:converters/p5-JSON \
		p5-Log-Report>=0:devel/p5-Log-Report \
		p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML-Simple>=0:textproc/p5-XML-LibXML-Simple \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
