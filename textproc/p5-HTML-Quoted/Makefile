# New ports collection makefile for:	textproc/p5-HTML-Quoted
# Date created:				01 September 2011
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Quoted
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Extract structure of quoted HTML mail message

BUILD_DEPENDS=	p5-HTML-Parser>=3.0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Quoted.3

.include <bsd.port.mk>
