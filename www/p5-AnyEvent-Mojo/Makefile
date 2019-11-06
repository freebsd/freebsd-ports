# $FreeBSD$

PORTNAME=	AnyEvent-Mojo
PORTVERSION=	0.8003
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to start async Mojo servers easily

BROKEN=		unfetchable

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-AnyEvent>=5.201:devel/p5-AnyEvent \
	p5-AnyEvent-HTTP>=1.43:www/p5-AnyEvent-HTTP \
	p5-Mojolicious>=0.991251:www/p5-Mojolicious
#	p5-Test-Deep>0:devel/p5-Test-Deep \
#	p5-Test-Exception>0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
