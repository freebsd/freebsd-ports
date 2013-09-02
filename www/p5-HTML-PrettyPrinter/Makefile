# New ports collection makefile for:	p5-HTML-PrettyPrinter
# Date created:				Wed Mar  1 15:41:13 EST 2006
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-PrettyPrinter
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Generate nice HTML files from HTML syntax trees

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::PrettyPrinter.3

.include <bsd.port.mk>
