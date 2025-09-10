PORTNAME=	Sisimai
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AKXLIX
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mail Analyzing Interface for bounce mails
WWW=		https://metacpan.org/release/Sisimai

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
		p5-JSON>=2.90:converters/p5-JSON

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
