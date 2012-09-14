# New ports collection makefile for:	Test-HTTP
# Date created:	   11 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-HTTP
PORTVERSION=	0.18
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test HTTP interactions

BUILD_DEPENDS=	p5-Class-Field>=0:${PORTSDIR}/devel/p5-Class-Field \
		p5-libwww>=5.827:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::HTTP.3 Test::HTTP::Syntax.3

.include <bsd.port.mk>
