# New ports collection makefile for:	Text::VimColor
# Date created:		2004-07-25
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Text-VimColor
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GE/GEOFFR/
PKGNAMEPREFIX=	p5-

MAINTAINER=	elvis@sslab.cs.ccu.edu.tw
COMMENT=	Syntax color text in HTML or XML using Vim

BUILD_DEPENDS=	${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		text-vimcolor.1
MAN3=		Text::VimColor.3

.include <bsd.port.mk>
