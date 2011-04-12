# New ports collection makefile for:	Chart-Math-Axis
# Date created:	   18 May 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Chart-Math-Axis
PORTVERSION=	1.06
CATEGORIES=	math graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implements an algorithm to find good values for chart axis

BUILD_DEPENDS=	p5-Params-Util>=0.15:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Chart::Math::Axis.3

.include <bsd.port.mk>
