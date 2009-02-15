# New ports collection makefile for:	POE-Filter-Transparent-SMTP
# Date created:	   06 Nov 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-Transparent-SMTP
PORTVERSION=	0.2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	SMTP transparency POE filter

BUILD_DEPENDS=	${SITE_PERL}/POE/Filter/Line.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::Transparent::SMTP.3

.include <bsd.port.mk>
