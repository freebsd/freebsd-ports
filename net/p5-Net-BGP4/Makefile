# New ports collection makefile for:	Net-BGP4
# Date created:	   10 September 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-BGP4
PORTVERSION=	0.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::BGP4.3 Net::BGP4::Notification.3 Net::BGP4::Peer.3 \
		Net::BGP4::Process.3 Net::BGP4::RIB.3 Net::BGP4::Update.3

.include <bsd.port.mk>
