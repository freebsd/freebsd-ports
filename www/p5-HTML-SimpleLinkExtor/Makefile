# New ports collection makefile for:	p5-HTML-SimpleLinkExtor
# Date created:			15 July 2004
# Whom:				Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-SimpleLinkExtor
PORTVERSION=	1.23
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This is a simple HTML link extractor

RUN_DEPENDS=	p5-HTML-Parser>=1.28:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN1=		linktractor.1
MAN3=		SimpleLinkExtor.3

.include <bsd.port.mk>
