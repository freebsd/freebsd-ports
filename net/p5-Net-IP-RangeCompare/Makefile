# New ports collection makefile for:	p5-Net-IP-RangeCompare
# Date created:		2010-11-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IP-RangeCompare
PORTVERSION=	4.025
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for IP Range Comparisons

RUN_DEPENDS=	p5-Data-IPV4-Range-Parse>=0.05:${PORTSDIR}/net/p5-Data-IPV4-Range-Parse \
		p5-Data-Range-Compare>=1.030:${PORTSDIR}/devel/p5-Data-Range-Compare

PERL_CONFIGURE=	yes

MAN3=		Net::IP::RangeCompare.3

.include <bsd.port.mk>
