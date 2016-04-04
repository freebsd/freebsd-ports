# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Lingua-EN-Fathom
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::EN::Fathom - Measure readability of English text

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

COMMON_DEPENDS=	p5-Lingua-EN-Syllable>0:textproc/p5-Lingua-EN-Syllable
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
