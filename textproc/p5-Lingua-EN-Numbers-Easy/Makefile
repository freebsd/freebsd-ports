# New ports collection makefile for:	Lingua-EN-Numbers-Easy
# Date created:				15 September 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Numbers-Easy
PORTVERSION=	2009110701
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl module providing hash access to Lingua::EN::Numbers objects

RUN_DEPENDS=	p5-Lingua-EN-Numbers>=1.01:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Lingua::EN::Numbers::Easy.3

.include <bsd.port.mk>
