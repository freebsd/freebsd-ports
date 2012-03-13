# New ports collection makefile for:	Pod-Strip
# Date created:	   			Feb 13 2007
# Whom:		   			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-Strip
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Remove POD from Perl code

PERL_MODBUILD=	yes

MAN3=		Pod::Strip.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Pod-Simple>=3.00:${PORTSDIR}/textproc/p5-Pod-Simple
BUILD_DEPENDS+=	${RUN_DEPENDS}
.endif

.include <bsd.port.post.mk>
