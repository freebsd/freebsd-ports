# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-TCLink
PORTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Net_TCLink.pm-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Module to for connecting to the TrustCommerce payment gateway

LICENSE=	LGPL21

USES=		perl5 ssl
USE_PERL5=	configure
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
