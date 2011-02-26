# New ports collection makefile for:	HTTP::Session::State::MobileAgentID
# Date created:		01 Aug 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Session-State-MobileAgentID
PORTVERSION=	0.45
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/T/TO/TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to maintain session IDs using mobile phone unique id

RUN_DEPENDS=	\
	p5-HTTP-MobileAgent>=0.28:${PORTSDIR}/www/p5-HTTP-MobileAgent \
	p5-HTTP-Session>=0.38:${PORTSDIR}/www/p5-HTTP-Session \
	p5-Net-CIDR-MobileJP>=0.20:${PORTSDIR}/net/p5-Net-CIDR-MobileJP
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTTP::Session::State::MobileAgentID.3

.include <bsd.port.mk>
