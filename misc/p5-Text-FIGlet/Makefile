# New ports collection makefile for:	p5-Text-Figlet
# Date created:				24 May 2002
# Whom:					Daniel B. Hemmerich <dan@spot.org>
#
# $FreeBSD$

PORTNAME=	Text-FIGlet
PORTVERSION=	1.06
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to provide FIGlet abilities, akin to banner

RUN_DEPENDS=	${LOCALBASE}/bin/figlet:${PORTSDIR}/misc/figlet

PERL_CONFIGURE=	yes


MAN3=		Text::FIGlet.3 \
		Text::charmap.3 \
		Text::figlet.3 \
		Text::minifig.3 \
		Text::showfigfonts.3

.include <bsd.port.mk>
