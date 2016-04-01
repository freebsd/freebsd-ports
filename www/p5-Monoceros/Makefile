# $FreeBSD$

PORTNAME=	Monoceros
PORTVERSION=	0.27
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZEBURO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PSGI/Plack server w/ event driven connection manager, prefork workers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-AnyEvent>=7.04:devel/p5-AnyEvent \
	p5-IO-FDPass>=1.0:devel/p5-IO-FDPass \
	p5-Net-CIDR-Lite>0:net/p5-Net-CIDR-Lite \
	p5-POSIX-Socket>0:net/p5-POSIX-Socket \
	p5-POSIX-getpeername>0:net/p5-POSIX-getpeername \
	p5-Plack>=1.0023:www/p5-Plack \
	p5-Starlet>=0.18:www/p5-Starlet \
	p5-Sys-Sendfile>=0.11:devel/p5-Sys-Sendfile
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-TCP>0:devel/p5-Test-TCP

USES=	perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
