# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	CGI-Ex
PORTVERSION=	2.41
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CGI utility suite - makes powerful application writing fun and easy

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Template-Alloy>=1.004:${PORTSDIR}/www/p5-Template-Alloy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${CP} -R ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
