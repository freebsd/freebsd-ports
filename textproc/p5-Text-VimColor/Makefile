# New ports collection makefile for:	Text::VimColor
# Date created:		2004-07-25
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Text-VimColor
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GE/GEOFFR/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Syntax color text in HTML or XML using Vim

BUILD_DEPENDS=	${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		text-vimcolor.1
MAN3=		Text::VimColor.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
