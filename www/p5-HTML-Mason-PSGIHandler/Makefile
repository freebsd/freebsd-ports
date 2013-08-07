# New ports collection makefile for:	www/p5-HTML-Mason-PSGIHandler
# Date created:				02 September 2011
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Mason-PSGIHandler
PORTVERSION=	0.52
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	PSGI handler for HTML::Mason

BUILD_DEPENDS=	p5-CGI-PSGI>0:${PORTSDIR}/www/p5-CGI-PSGI \
		p5-HTML-Mason>0:${PORTSDIR}/www/p5-HTML-Mason
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Plack>=0:${PORTSDIR}/www/p5-Plack

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::Mason::PSGIHandler.3

.include <bsd.port.mk>
