# New ports collection makefile for:	p5-Pod-Autopod
# Date created:				31 Oct, 2009
# Whom:		   			Wen Heping<wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-Autopod
PORTVERSION=	1.08
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generates pod documentation by analysing perl modules

BUILD_DEPENDS=	p5-Pod-Abstract>=0.19:${PORTSDIR}/textproc/p5-Pod-Abstract
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		autopod.1
MAN3=		Pod::Autopod.3

.include <bsd.port.mk>
