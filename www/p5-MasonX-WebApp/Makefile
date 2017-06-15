# Created by: Travis Campbell <hcoyote@ghostar.org>
# $FreeBSD$

PORTNAME=	MasonX-WebApp
PORTVERSION=	0.12
PORTREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Works with HTML::Mason to do processing before Mason is invoked

BUILD_DEPENDS=	mp2bug:www/mod_perl2 \
		p5-HTML-Mason>=0:www/p5-HTML-Mason \
		p5-Apache-Session-Wrapper>=0:www/p5-Apache-Session-Wrapper \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Class-Factory-Util>=0:devel/p5-Class-Factory-Util \
		p5-URI>0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Output>=0:devel/p5-Test-Output

USE_APACHE_RUN=	22+
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
