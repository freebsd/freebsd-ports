# Created by: Murilo Opsfelder <mopsfelder@gmail.com>
# $FreeBSD$

PORTNAME=	Mojolicious
PORTVERSION=	6.64
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	High-level MVC web framework written in Perl

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EV IPV6 TLS
OPTIONS_DEFAULT=EV TLS

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

EV_DESC=		High-performance event loop via devel/p5-EV
EV_BUILD_DEPENDS=	p5-EV>=4:devel/p5-EV
EV_RUN_DEPENDS=		p5-EV>=4:devel/p5-EV

IPV6_CATEGORIES=	ipv6
IPV6_BUILD_DEPENDS=	p5-IO-Socket-IP>=0.37:net/p5-IO-Socket-IP
IPV6_RUN_DEPENDS=	p5-IO-Socket-IP>=0.37:net/p5-IO-Socket-IP

TLS_BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.75:security/p5-IO-Socket-SSL
TLS_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.75:security/p5-IO-Socket-SSL

.include <bsd.port.mk>
