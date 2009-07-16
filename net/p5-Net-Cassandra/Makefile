# New ports collection makefile for:	p5-Net-Cassandra
# Date created:		2009-07-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Cassandra
PORTVERSION=	0.33
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Interface to Cassandra

RUN_DEPENDS=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-StrictConstructor>0:${PORTSDIR}/devel/p5-MooseX-StrictConstructor

MAN3=		Net::Cassandra.3
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
