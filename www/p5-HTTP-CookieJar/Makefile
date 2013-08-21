# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-CookieJar
PORTVERSION=	0.005
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minimalist HTTP user agent cookie jar

LICENSE=	AL2

BUILD_DEPENDS=	p5-HTTP-Date>=0:${PORTSDIR}/www/p5-HTTP-Date
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Mozilla-PublicSuffix>=0:${PORTSDIR}/dns/p5-Mozilla-PublicSuffix \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Time-Mock>=0:${PORTSDIR}/devel/p5-Time-Mock

USE_PERL5=	configure
USES=		perl5

MAN3=		HTTP::CookieJar.3 \
		HTTP::CookieJar::LWP.3

.include <bsd.port.mk>
