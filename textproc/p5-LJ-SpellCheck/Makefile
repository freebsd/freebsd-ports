# New ports collection makefile for:	p5-LJ-SpellCheck
# Date created:				25 Mar 2001
# Whom:					Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	LJ-SpellCheck
PORTVERSION=	1.0
CATEGORIES=	textproc perl5
MASTER_SITES=	http://livejournal.com/files/code/spellcheck/ \
		ftp://ftp.livejournal.com/code/spellcheck/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML highlighting misspellings using ispell compatible program

RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

PERL_CONFIGURE=	yes

MAN3=		LJ::SpellCheck.3

.include <bsd.port.mk>
