# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-API
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module to interact with a JSON API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=2:converters/p5-JSON \
		p5-libwww>=0:www/p5-libwww \
		p5-URI-Encode>0:www/p5-URI-Encode
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-Capture>=0:devel/p5-IO-Capture \
		p5-Test-Fake-HTTPD>=0:devel/p5-Test-Fake-HTTPD \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
