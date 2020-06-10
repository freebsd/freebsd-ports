# Created by: Murilo Opsfelder <mopsfelder@gmail.com>
# $FreeBSD$

PORTNAME=	Mojolicious
PORTVERSION=	8.53
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	High-level MVC web framework written in Perl

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-IO-Socket-Socks>=0.64:net/p5-IO-Socket-Socks \
		p5-Role-Tiny>=2.000001:devel/p5-Role-Tiny \
		${JSONXS_BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
TEST_ARGS=	TEST_ASYNC_AWAIT=1 TEST_EV=1 TEST_HYPNOTOAD=1 \
		TEST_IPV6=1 TEST_MORBO=1 TEST_ONLINE=1 TEST_PREFORK=1 \
		TEST_SOCKS=1 TEST_SUBPROCESS=1 TEST_TLS=1 TEST_UNIX=1 \
		HARNESS_OPTIONS=j$$(sysctl -n hw.ncpu)

OPTIONS_DEFINE=	EV JSONXS TLS
OPTIONS_DEFAULT=EV TLS

EV_DESC=		High-performance event loop via p5-EV
EV_BUILD_DEPENDS=	p5-EV>=4:devel/p5-EV
EV_RUN_DEPENDS=		p5-EV>=4:devel/p5-EV

JSONXS_DESC=		High-performance JSON parsing via p5-Cpanel-JSON-XS
JSONXS_BUILD_DEPENDS=	p5-Cpanel-JSON-XS>=4.09:converters/p5-Cpanel-JSON-XS
JSONXS_RUN_DEPENDS=	p5-Cpanel-JSON-XS>=4.09:converters/p5-Cpanel-JSON-XS

TLS_BUILD_DEPENDS=	p5-IO-Socket-SSL>=2.009:security/p5-IO-Socket-SSL
TLS_RUN_DEPENDS=	p5-IO-Socket-SSL>=2.009:security/p5-IO-Socket-SSL

.include <bsd.port.mk>
