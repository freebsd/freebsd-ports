# New ports collection makefile for:	POE-Component-Client-NNTP
# Date created:	   17 October 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-NNTP
PORTVERSION=	2.20
CATEGORIES=	news perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for non-blocking NNTP access

RUN_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Pluggable>=0:${PORTSDIR}/devel/p5-POE-Component-Pluggable
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-POE-Server-TCP>=0:${PORTSDIR}/devel/p5-Test-POE-Server-TCP

PERL_CONFIGURE= yes

MAN3=		POE::Component::Client::NNTP.3 \
		POE::Component::Client::NNTP::Constants.3

.include <bsd.port.mk>
