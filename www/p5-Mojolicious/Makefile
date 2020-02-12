# Created by: Murilo Opsfelder <mopsfelder@gmail.com>
# $FreeBSD$

PORTNAME=	Mojolicious
PORTVERSION=	8.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	High-level MVC web framework written in Perl

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Role-Tiny>=2.000001:devel/p5-Role-Tiny \
		${JSONXS_BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

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
