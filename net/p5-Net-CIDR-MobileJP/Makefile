# New ports collection makefile for:	Net::CIDR::MobileJP
# Date created:		19 Jul 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-CIDR-MobileJP
PORTVERSION=	0.20
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for mobile IP address in Japan

RUN_DEPENDS=	\
	p5-File-ShareDir>=1.02:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-Net-CIDR-Lite>=0.2:${PORTSDIR}/net/p5-Net-CIDR-Lite \
	ja-p5-WWW-MobileCarrierJP>=0.37:${PORTSDIR}/japanese/p5-WWW-MobileCarrierJP \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::CIDR::MobileJP.3 \
	Net::CIDR::net-cidr-mobilejp-scraper.3

.include <bsd.port.mk>
