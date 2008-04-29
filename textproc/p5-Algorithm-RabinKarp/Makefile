# New ports collection makefile for:	p5-Algorithm-RabinKarp
# Date created:				24 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-RabinKarp
PORTVERSION=	0.41
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NN/NNUNLEY
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}_1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rabin-Karp streaming hash

BUILD_DEPENDS=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Algorithm::RabinKarp.3 Algorithm::RabinKarp::Util.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
