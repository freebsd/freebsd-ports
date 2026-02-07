PORTNAME=	HTTP-OAI
PORTVERSION=	4.12
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.ne@gmx.net
COMMENT=	HTTP::OAI - API for the OAI-PMH
WWW=		https://metacpan.org/dist/HTTP-OAI

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Encode>=2.12:converters/p5-Encode \
		p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-libwww>=5.818:www/p5-libwww \
		p5-URI>0:net/p5-URI \
		p5-XML-LibXML>=1.60:textproc/p5-XML-LibXML \
		p5-XML-NamespaceSupport>0:textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX-Base>=1.04:textproc/p5-XML-SAX-Base \
		p5-XML-SAX>0:textproc/p5-XML-SAX

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
