# Created by: Jesse McConnell <jesse@gallup.com>
# $FreeBSD$

PORTNAME=	Net-Server
PORTVERSION=	2.007
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Configurable base class for writing internet servers in Perl

BUILD_DEPENDS=	p5-IO-Multiplex>=1.01:${PORTSDIR}/devel/p5-IO-Multiplex
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IPV6

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
BUILD_DEPENDS+=	p5-Socket6>=0.23:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS+=	p5-Socket6>=0.23:${PORTSDIR}/net/p5-Socket6
.endif

.include <bsd.port.mk>
