# New ports collection makefile for:	Validate-Net
# Date created:	   10 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Validate-Net
PORTVERSION=	0.5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Format validation and more for Net:: related strings

BUILD_DEPENDS=	${SITE_PERL}/Class/Default.pm:${PORTSDIR}/devel/p5-Class-Default
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Validate::Net.3

.include <bsd.port.mk>
