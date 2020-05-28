# Created by: will
# $FreeBSD$

PORTNAME=	WWW-Robot
PORTVERSION=	0.026
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Configurable web traversal engine in Perl

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-libwww>=0:www/p5-libwww \
		p5-HTML-Tagset>=0:www/p5-HTML-Tagset

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
