# $FreeBSD$

PORTNAME=	Plack-Middleware-JSConcat
PORTVERSION=	0.29
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to concatenate JavaScripts

RUN_DEPENDS=	\
	p5-IPC-Run3>0:${PORTSDIR}/devel/p5-IPC-Run3 \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
