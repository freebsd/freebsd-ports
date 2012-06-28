# New ports collection makefile for:	p5-Chemistry-InternalCoords
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-InternalCoords
PORTVERSION=	0.18
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Represent the position of an atom using internal coordinates

BUILD_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-Bond-Find>=0:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		p5-Chemistry-Canonicalize>=0:${PORTSDIR}/science/p5-Chemistry-Canonicalize
RUN_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-Bond-Find>=0:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		p5-Chemistry-Canonicalize>=0:${PORTSDIR}/science/p5-Chemistry-Canonicalize

MAN3=	Chemistry::InternalCoords.3 Chemistry::InternalCoords::Builder.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
