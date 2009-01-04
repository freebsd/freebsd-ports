# New ports collection makefile for:	p5-Text-Figlet
# Date created:				24 May 2002
# Whom:					Daniel B. Hemmerich <dan@spot.org>
#
# $FreeBSD$

PORTNAME=	Text-FIGlet
PORTVERSION=	2.01
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Perl module to provide FIGlet abilities, akin to banner

RUN_DEPENDS=	${LOCALBASE}/bin/figlet:${PORTSDIR}/misc/figlet

PERL_CONFIGURE=	yes

MAN1=		charmap.pl.1 figlet.pl.1 minifig.pl.1 showfigfonts.pl.1
MAN3=		Text::FIGlet.3 Text::FIGlet::Control.3 Text::FIGlet::Font.3 \
		Text::LICENSE.3

.include <bsd.port.mk>
