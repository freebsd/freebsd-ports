# New ports collection makefile for:	textproc/p5-Makefile-Parser
# Date created:				11 April 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Makefile-Parser
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/A/AG/AGENT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Makefile::Parser - A Simple Parser for Makefiles

RUN_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils

PERL_CONFIGURE=	yes

MAN1=	plmake.1
MAN3=	Makefile::Parser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced
.endif

.include <bsd.port.post.mk>
