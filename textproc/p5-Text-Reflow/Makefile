# New ports collection makefile for:	textproc/p5- Text-Reflow
# Date created:				2 August 2002
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Text-Reflow
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl module for reflowing text files

PERL_CONFIGURE=	yes

MAN3=		Text::Reflow.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} > 500800
EXTRA_PATCHES=	${PATCHDIR}/5.8-Reflow.pm
.endif
.if ${PERL_LEVEL} < 500601
IGNORE= "Requires perl 5.6.1"
.endif

.include <bsd.port.post.mk>
