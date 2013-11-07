# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-Autopod
PORTVERSION=	1.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AHERNIT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generates pod documentation by analysing perl modules

BUILD_DEPENDS=	p5-Pod-Abstract>=0.19:${PORTSDIR}/textproc/p5-Pod-Abstract
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
