# New ports collection makefile for:	Lingua-EN-Numbers-Easy
# Date created:				15 September 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Numbers-Easy
PORTVERSION=	1.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua/ABIGAIL
PKGNAMEPREFIX=	p5-
DISTNAME=	Lingua_EN_Numbers_Easy-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl module providing hash access to Lingua::EN::Numbers objects

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/Numbers.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers
RUN_DEPENDS=	${SITE_PERL}/Lingua/EN/Numbers.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers

WRKSRC=		${WRKDIR}/Easy-${PORTVERSION}

PERL_CONFIGURE=	yes

MAN3=		Lingua::EN::Numbers::Easy.3

.include <bsd.port.mk>
