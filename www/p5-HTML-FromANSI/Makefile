# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	HTML-FromANSI
PORTVERSION=	2.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mark up ANSI sequences as HTML

LICENSE=	ART10 GPLv1 MIT
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Term-VT102-Boundless>=0:devel/p5-Term-VT102-Boundless

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
