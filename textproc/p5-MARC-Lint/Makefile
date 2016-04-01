# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MARC-Lint
PORTVERSION=	1.46
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Mechanism for validating MARC records

BUILD_DEPENDS=	p5-MARC-Record>=0:textproc/p5-MARC-Record \
		p5-Business-ISBN>=2.03:misc/p5-Business-ISBN
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/marc-lint

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
