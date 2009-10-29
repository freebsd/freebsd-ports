# New ports collection makefile for:   devel/p5-Sort-Key-IPv4
# Date created:                                15 November 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sort-Key-IPv4
PORTVERSION=	0.02
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Perl extension for sorting IPv4 addresses

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Sort/Key.pm:${PORTSDIR}/devel/p5-Sort-Key
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Sort/Key.pm:${PORTSDIR}/devel/p5-Sort-Key

PERL_CONFIGURE=	5.8.0+

MAN3=	Sort::Key::IPv4.3

.include <bsd.port.mk>
