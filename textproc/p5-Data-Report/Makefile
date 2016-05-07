# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Report
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Data::Report - Framework for flexible reporting

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

COMMON_DEPENDS=	p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-Text-CSV_XS>0:textproc/p5-Text-CSV_XS
BUILD_DEPENDS=	p5-Module-Build>=0.28:devel/p5-Module-Build \
		${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
