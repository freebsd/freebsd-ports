# New ports collection makefile for:	Test-HTTP
# Date created:	   11 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-HTTP
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Test HTTP interactions

RUN_DEPENDS=	p5-Class-Field>=0:${PORTSDIR}/devel/p5-Class-Field \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Test::HTTP.3 Test::HTTP::Syntax.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
