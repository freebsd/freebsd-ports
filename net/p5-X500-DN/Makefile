# New ports collection makefile for:	X500-DN
# Date created:	   22 October 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	X500-DN
PORTVERSION=	0.29
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handle X.500 DNs (Distinguished Names), parse, and format them

BUILD_DEPENDS=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		X500::DN.3 X500::RDN.3

.include <bsd.port.mk>
