# New ports collection makefile for:	Net::TCLink
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-TCLink
PORTVERSION=	3.3.1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-
DISTNAME=	Net_TCLink.pm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A client library to for connecting to the TrustCommerce payment gateway

PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Net::TCLink.3

.include <bsd.port.mk>
