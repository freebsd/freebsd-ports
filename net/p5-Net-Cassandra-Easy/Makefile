# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Cassandra-Easy
PORTVERSION=	0.15
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perlish interface to the Cassandra database

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Hash-Merge>=0:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Modern-Perl>=0:${PORTSDIR}/lang/p5-Modern-Perl \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
