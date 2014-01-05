# $FreeBSD$

PORTNAME=	Net-CIDR-MobileJP
PORTVERSION=	0.24
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for mobile IP address in Japan

RUN_DEPENDS=	\
	p5-File-ShareDir>=1.02:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-Net-CIDR-Lite>=0.21:${PORTSDIR}/net/p5-Net-CIDR-Lite \
	ja-p5-WWW-MobileCarrierJP>=0.55:${PORTSDIR}/japanese/p5-WWW-MobileCarrierJP \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
