# New ports collection makefile for:	Net-BGP4
# Date created:	   10 September 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-BGP
PORTVERSION=	0.08
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Border Gateway Protocol version 4 speaker/listener library

PERL_CONFIGURE=	yes

MAN3=		Net::BGP.3 Net::BGP::ASPath.3 Net::BGP::NLRI.3 \
		Net::BGP::Notification.3 Net::BGP::Peer.3 Net::BGP::Process.3 \
		Net::BGP::Refresh.3 Net::BGP::Transport.3 Net::BGP::Update.3

.include <bsd.port.mk>
