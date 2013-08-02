# Created by: chinsan
# $FreeBSD$

PORTNAME=	WebService-Rakuten
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Rakuten WebService API

RUN_DEPENDS=	ja-p5-Unicode-Japanese>=0:${PORTSDIR}/japanese/p5-Unicode-Japanese \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

MAN3=		WebService::Rakuten.3

.include <bsd.port.mk>
