# Created by: Alexander Koch <fbsd@meersau.de>
# $FreeBSD$

PORTNAME=	HTML-Chunks
PORTVERSION=	1.55.1
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple nested template engine for HTML, XML and XHTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-stringy>=0:devel/p5-IO-stringy
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
