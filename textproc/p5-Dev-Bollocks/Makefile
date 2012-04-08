# New ports collection makefile for:	p5-Dev-Bollocks
# Date created:		2012-04-08
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dev-Bollocks
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TELS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to generate bollocks straight from middle management

BUILD_DEPENDS=	p5-Math-String>=0:${PORTSDIR}/math/p5-Math-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Dev::Bollocks.3

.include <bsd.port.mk>
