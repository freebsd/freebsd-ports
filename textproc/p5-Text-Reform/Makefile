# New ports collection makefile for:	textproc/p5-Text-Reform
# Date created:				2 August 2002
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Text-Reform
PORTVERSION=	1.11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Manual text wrapping and reformatting

PERL_CONFIGURE=	yes

MAN3=		Text::Reform.3

pre-configure:
	@${FIND} ${WRKSRC} -name \*.orig -delete

.include <bsd.port.mk>
