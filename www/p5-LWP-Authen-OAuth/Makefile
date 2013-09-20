# $FreeBSD$

PORTNAME=	LWP-Authen-OAuth
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to generate signed OAuth requests

RUN_DEPENDS=	\
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	LWP::Authen::OAuth.3

NO_STAGE=	yes
.include <bsd.port.mk>
