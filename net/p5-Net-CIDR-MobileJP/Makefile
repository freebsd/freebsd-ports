# $FreeBSD$

PORTNAME=	Net-CIDR-MobileJP
PORTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for mobile IP address in Japan

RUN_DEPENDS=	\
	p5-File-ShareDir>=1.02:devel/p5-File-ShareDir \
	p5-Net-CIDR-Lite>=0.21:net/p5-Net-CIDR-Lite \
	ja-p5-WWW-MobileCarrierJP>=0.55:japanese/p5-WWW-MobileCarrierJP \
	p5-YAML>0:textproc/p5-YAML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	net-cidr-mobilejp-scraper.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
