# New ports collection makefile for:	p5-Net-MAC
# Date created:				25 Oct 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-MAC
PORTVERSION=	1.6
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Perl 5 module for representing and manipulating MAC addresses

BUILD_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww

MAN3=		Net::MAC.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
