# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=       WWW-Salesforce
PORTVERSION=    0.25
CATEGORIES=     www perl5
MASTER_SITES=   CPAN
PKGNAMEPREFIX=  p5-

MAINTAINER=     matthew@FreeBSD.org
COMMENT=        Simple abstraction layer between SOAP::Lite and Salesforce.com

LICENSE=        ART10 GPLv1
LICENSE_COMB=   dual

BUILD_DEPENDS=	p5-SOAP-Lite>=0.68:net/p5-SOAP-Lite \
		p5-Crypt-SSLeay>=0.56:security/p5-Crypt-SSLeay
RUN_DEPENDS:=   ${BUILD_DEPENDS}
TEST_DEPENDS=   p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

NO_ARCH=        yes
USES=           perl5
USE_PERL5=      configure

.include <bsd.port.mk>
