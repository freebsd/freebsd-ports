PORTNAME=	XML-Atom
PORTVERSION=	0.43
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for Atom feed and API implementation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-TimeZone>=0:devel/p5-DateTime-TimeZone \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=2.0202,1:textproc/p5-XML-LibXML \
		p5-XML-XPath>=1.20:textproc/p5-XML-XPath \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
