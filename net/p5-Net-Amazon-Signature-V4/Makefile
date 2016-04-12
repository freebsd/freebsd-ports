# $FreeBSD$

PORTNAME=	Net-Amazon-Signature-V4
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for AWS signature V4, AWS4-HMAC-SHA256

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-DateTime-Format-Strptime>0:devel/p5-DateTime-Format-Strptime \
	p5-File-Slurp>0:devel/p5-File-Slurp \
	p5-libwww>0:www/p5-libwww \
	p5-Net>0:net/p5-Net
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
