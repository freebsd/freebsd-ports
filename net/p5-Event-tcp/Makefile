# New ports collection makefile for:	p5-Event-tcp
# Date created:				2009-11-15
# Whom:					steinex
#
# $FreeBSD$
#

PORTNAME=	Event-tcp
PORTVERSION=	0.14
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	steinex@nognu.de
COMMENT=	Glue code to build client-server style TCP-based services

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event \
		${SITE_PERL}/${PERL_ARCH}/Ioctl.pm:${PORTSDIR}/devel/p5-Ioctl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Event::tcpsession.3

.include <bsd.port.mk>
