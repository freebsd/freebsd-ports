# Created by: Zane C. Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Net-WhitePages
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides access to the XML API for WhitePages.com

BUILD_DEPENDS=	p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
