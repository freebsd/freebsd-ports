# $FreeBSD$

PORTNAME=	Net-Google-Analytics
PORTVERSION=	3.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Google Analytics Data Export API

RUN_DEPENDS=	\
	p5-Class-XSAccessor>=1.05:${PORTSDIR}/devel/p5-Class-XSAccessor \
	p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
