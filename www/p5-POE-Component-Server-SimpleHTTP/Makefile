# $FreeBSD$

PORTNAME=	POE-Component-Server-SimpleHTTP
PORTVERSION=	2.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to serve HTTP requests in POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.9:devel/p5-Moose \
		p5-MooseX-POE>=0.205:devel/p5-MooseX-POE \
		p5-POE>=1.0000:devel/p5-POE \
		p5-libwww>0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-POE-Component-Client-HTTP>=0:www/p5-POE-Component-Client-HTTP \
		p5-POE-Filter-HTTP-Parser>=1.06:www/p5-POE-Filter-HTTP-Parser \
		p5-Test-POE-Client-TCP>0.1:devel/p5-Test-POE-Client-TCP

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

SSL_DESC=		SSL support (POE::Component::SSLify)
SSL_BUILD_DEPENDS=	p5-POE-Component-SSLify>=0.04:security/p5-POE-Component-SSLify
SSL_RUN_DEPENDS=	${SSL_BUILD_DEPENDS}

.include <bsd.port.mk>
