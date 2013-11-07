# Created by: Murilo Opsfelder <mopsfelder@gmail.com>
# $FreeBSD$

PORTNAME=	Mojolicious
PORTVERSION=	4.55
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SRI
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

IPV6_BUILD_DEPENDS=	p5-IO-Socket-IP>=0.16:${PORTSDIR}/net/p5-IO-Socket-IP
IPV6_CATEGORIES=	ipv6
IPV6_RUN_DEPENDS=	p5-IO-Socket-IP>=0.16:${PORTSDIR}/net/p5-IO-Socket-IP
TLS_BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.75:${PORTSDIR}/security/p5-IO-Socket-SSL
TLS_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.75:${PORTSDIR}/security/p5-IO-Socket-SSL

.include <bsd.port.mk>
