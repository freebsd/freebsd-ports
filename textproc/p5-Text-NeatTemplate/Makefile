# New ports collection makefile for:	textproc/p5-Text-NeatTemplate
# Date created:				Wed Sep 20 12:37:36 CST 2006
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-NeatTemplate
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A fast, middleweight template engine

PERL_MODBUILD=	yes

MAN3=		Text::NeatTemplate.3

post-patch:
		${CHMOD} u+w ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
