# New ports collection makefile for:	www/p5-Feed-Find
# Date created:				28 July 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Feed-Find
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/B/BT/BTROTT
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Syndication feed auto-discovery

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Feed::Find.3

.include <bsd.port.mk>
