# $FreeBSD$

PORTNAME=	Plack-Handler-SCGI
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for PSGI handler on SCGI daemon

RUN_DEPENDS=	\
	p5-Plack>=0.9901:${PORTSDIR}/www/p5-Plack \
	p5-SCGI>0:${PORTSDIR}/www/p5-SCGI \
	p5-Try-Tiny>=0.04:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
