# New ports collection makefile for:	Net-BGP4
# Date created:	   10 September 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-BGP
PORTVERSION=	0.13
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Border Gateway Protocol version 4 speaker/listener library

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/TAP/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::BGP.3 Net::BGP::ASPath.3 Net::BGP::NLRI.3 \
		Net::BGP::Notification.3 Net::BGP::Peer.3 Net::BGP::Process.3 \
		Net::BGP::Refresh.3 Net::BGP::Transport.3 Net::BGP::Update.3

.include <bsd.port.mk>
