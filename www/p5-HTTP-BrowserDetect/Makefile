# New ports collection makefile for:	HTTP-BrowserDetect
# Date created:	   10 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	HTTP-BrowserDetect
PORTVERSION=	1.28
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OALDERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Determine the Web browser, version, OS from an HTTP user agent string

TEST_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-JSON-PP>=0:${PORTSDIR}/converters/p5-JSON-PP

PERL_CONFIGURE=	yes

MAN3=		HTTP::BrowserDetect.3

.include <bsd.port.mk>
