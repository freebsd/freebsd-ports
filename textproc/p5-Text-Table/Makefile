# New ports collection makefile for:	textproc/p5-Text-Table
# Date created:				May  2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Table
PORTVERSION=	1.102
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Organize Data in Tables

BUILD_DEPENDS=	${SITE_PERL}/Text/Aligner.pm:${PORTSDIR}/textproc/p5-Text-Aligner
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Table.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=                This program only support perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
