# New ports collection makefile for:	POE-Component-Client-HTTP
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-HTTP
PORTVERSION=	0.8950
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE component for non-blocking/concurrent HTTP queries

BUILD_DEPENDS=	p5-POE>=1.280:${PORTSDIR}/devel/p5-POE \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-URI>=1.24:${PORTSDIR}/net/p5-URI \
		p5-POE-Component-Client-Keepalive>=0.261:${PORTSDIR}/net/p5-POE-Component-Client-Keepalive
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::HTTP.3 \
		POE::Component::Client::HTTP::Request.3 \
		POE::Component::Client::HTTP::RequestFactory.3 \
		POE::Filter::HTTPChunk.3 POE::Filter::HTTPHead.3

.include <bsd.port.mk>
