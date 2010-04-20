# New ports collection makefile for:	Pod-Eventual
# Date created:		27 December 2009
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	Pod-Eventual
PORTVERSION=	0.093330
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read a POD document as a series of trivial events

BUILD_DEPENDS=	p5-Mixin-Linewise>=0.001:${PORTSDIR}/devel/p5-Mixin-Linewise \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES
MAN3=	Pod::Eventual.3\
		Pod::Eventual::Simple.3

.include <bsd.port.mk>
