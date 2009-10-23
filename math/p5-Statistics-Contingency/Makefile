# New ports collection makefile for:	math/p5-Statistics-Contingency
# Date created:				Tue Dec 30 19:57:00 CST 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Statistics-Contingency
PORTVERSION=	0.08
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Calculate precision, recall, F1, accuracy, etc

BUILD_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Statistics::Contingency.3

.include <bsd.port.mk>
