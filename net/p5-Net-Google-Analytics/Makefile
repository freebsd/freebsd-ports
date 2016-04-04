# $FreeBSD$

PORTNAME=	Net-Google-Analytics
PORTVERSION=	3.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Google Analytics Data Export API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-XSAccessor>=1.05:devel/p5-Class-XSAccessor \
	p5-JSON>0:converters/p5-JSON \
	p5-libwww>0:www/p5-libwww \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
