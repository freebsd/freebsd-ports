# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	XML-Atom
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for Atom feed and API implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-TimeZone>=0:devel/p5-DateTime-TimeZone \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-LWP-Authen-Wsse>=0:www/p5-LWP-Authen-Wsse \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=1.69:textproc/p5-XML-LibXML \
		p5-XML-XPath>=0:textproc/p5-XML-XPath \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
