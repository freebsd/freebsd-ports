# New ports collection makefile for:	p5-HTML-Packer
# Date created:		2011-07-23
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Packer
PORTVERSION=	1.002.001
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Another HTML code cleaner

RUN_DEPENDS=	p5-Regexp-RegGrp>=1.001.001:${PORTSDIR}/devel/p5-Regexp-RegGrp

PERL_CONFIGURE=	5.8.9+

MAN3=		HTML::Packer.3

.include <bsd.port.mk>
