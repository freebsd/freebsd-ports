# New ports collection makefile for:	p5-Net-YAP
# Date created:		2010-01-21
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-YAP
PORTVERSION=	0.5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Conduit to communicate with the Yahoo! Application Platform

BUILD_DEPENDS=	p5-Net-OAuth-Simple>=1.0:${PORTSDIR}/net/p5-Net-OAuth-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::YAP.3

.include <bsd.port.mk>
