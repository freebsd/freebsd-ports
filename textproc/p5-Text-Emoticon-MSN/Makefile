# New ports collection makefile for:	textproc/p5-Text-Emoticon-MSN
# Date created:				26 December 2009
# Whom:					Alex Deiter <Alex.Deiter@Gmail.COM>
#
# $FreeBSD$
#

PORTNAME=	Text-Emoticon-MSN
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	Emoticon filter of MSN Messenger

BUILD_DEPENDS=	p5-Text-Emoticon>=0.02:${PORTSDIR}/textproc/p5-Text-Emoticon
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Text::Emoticon::MSN.3

.include <bsd.port.mk>
