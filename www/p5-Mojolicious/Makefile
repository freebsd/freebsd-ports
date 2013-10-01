# Created by: Murilo Opsfelder <mopsfelder@gmail.com>
# $FreeBSD$

PORTNAME=	Mojolicious
PORTVERSION=	4.42
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	High level MVC web framework written in Perl

LICENSE=	ART20

BUILD_DEPENDS=	p5-EV>=4:${PORTSDIR}/devel/p5-EV
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IPV6 TLS
OPTIONS_DEFAULT=TLS

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=	ipv6
BUILD_DEPENDS+=	p5-IO-Socket-IP>=0.16:${PORTSDIR}/net/p5-IO-Socket-IP
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.16:${PORTSDIR}/net/p5-IO-Socket-IP
.endif

.if ${PORT_OPTIONS:MTLS}
BUILD_DEPENDS+=	p5-IO-Socket-SSL>=1.75:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS+=	p5-IO-Socket-SSL>=1.75:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.include <bsd.port.mk>
