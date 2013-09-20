# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	LWP-ConnCache-MaxKeepAliveRequests
PORTVERSION=	0.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A connection cache that enforces a max keep alive limit

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		LWP::ConnCache::MaxKeepAliveRequests.3

NO_STAGE=	yes
.include <bsd.port.mk>
