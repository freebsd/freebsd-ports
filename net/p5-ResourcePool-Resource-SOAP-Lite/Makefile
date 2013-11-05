# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ResourcePool-Resource-SOAP-Lite
PORTVERSION=	1.0103
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	CPAN:MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	ResourcePool wrapper for SOAP::Lite

RUN_DEPENDS=	p5-ResourcePool>=1.0100:${PORTSDIR}/devel/p5-ResourcePool \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
