# New ports collection makefile for:	p5-Math-RandomOrg
# Date created:				29 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-RandomOrg
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Retrieve random numbers and data from random.org

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Math::RandomOrg.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
