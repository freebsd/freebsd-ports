# New ports collection makefile for:	Text-Emoticon-GoogleTalk
# Date created:		2006/07/21
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Text-Emoticon-GoogleTalk
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	Emoticon filter of GoogleTalk

PERL_CONFIGURE=	yes

MAN3=		Text::Emoticon::GoogleTalk.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
