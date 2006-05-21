# New ports collection makefile for:	p5-Pod-LaTeX
# Date created:		2006-02-27
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-LaTeX
PORTVERSION=	0.58
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	paul@aps.org
COMMENT=	Convert Pod to LaTeX

BROKEN=		Incorrect pkg-plist

PERL_CONFIGURE=	yes

MAN1=		pod2latex.1

MAN3=		Pod::LaTeX.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-Pod-Parser
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
