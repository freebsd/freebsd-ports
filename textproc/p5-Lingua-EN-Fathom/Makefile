# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Lingua-EN-Fathom
PORTVERSION=	1.15
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::EN::Fathom - Measure readability of English text

COMMON_DEPENDS=	p5-Lingua-EN-Syllable>0:${PORTSDIR}/textproc/p5-Lingua-EN-Syllable
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Lingua::EN::Fathom.3

NO_STAGE=	yes
.include <bsd.port.mk>
