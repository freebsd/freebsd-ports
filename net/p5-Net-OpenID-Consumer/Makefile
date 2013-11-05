# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-OpenID-Consumer
PORTVERSION=	1.15
CATEGORIES=	net security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for consumers of OpenID identities

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Net-OpenID-Common>=1.18:${PORTSDIR}/security/p5-Net-OpenID-Common \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.if defined(MAINTAINER_MODE)
regression-test: build
	cd ${WRKSRC} && ${MAKE} test
.endif

.include <bsd.port.mk>
