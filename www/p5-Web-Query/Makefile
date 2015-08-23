# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Web-Query
PORTVERSION=	0.29
CATEGORIES=	www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet another scraping library like jQuery

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Selector-XPath>=0.06:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-TreeBuilder-XPath>=0.12:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-libwww>=6:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
