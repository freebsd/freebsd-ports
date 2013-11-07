# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Authentication-CDBI
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CDBI Authentication for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Model-CDBI>=0:${PORTSDIR}/www/p5-Catalyst-Model-CDBI \
		p5-Catalyst-Plugin-Session-FastMmap>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-FastMmap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
