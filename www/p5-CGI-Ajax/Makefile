# New ports collection makefile for:	www/p5-CGI-Ajax
# Date created:				19 September 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Ajax
PORTVERSION=	0.707
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A module for writing AJAX/DHTML-based web apps

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	CGI::Ajax.3

.include <bsd.port.mk>
