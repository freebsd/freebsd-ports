# New ports collection makefile for:	p5-Net-Cassandra-Easy
# Date created:		2010-04-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Cassandra-Easy
PORTVERSION=	0.15
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perlish interface to the Cassandra database

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Hash-Merge>=0:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Modern-Perl>=0:${PORTSDIR}/lang/p5-Modern-Perl \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

PERL_CONFIGURE=	yes
USE_PERL5=	5.10.0+

MAN3=		Net::Cassandra::Easy.3

.include <bsd.port.mk>
