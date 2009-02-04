# New ports collection makefile for:	p5-LWP-ConnCache-MaxKeepAliveRequests
# Date created:				2009-02-04
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	LWP-ConnCache-MaxKeepAliveRequests
PORTVERSION=	0.32
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A connection cache that enforces a max keep alive limit

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		LWP::ConnCache::MaxKeepAliveRequests.3

.include <bsd.port.mk>
