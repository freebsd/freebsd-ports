# New ports collection makefile for:	POE-Component-Spread
# Date created:	   21 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Spread
PORTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Handle Spread communications in POE

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Spread.pm:${PORTSDIR}/net/spread
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES

MAN3=		POE::Component::Spread.3

.include <bsd.port.mk>
