# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	CGI-Ex
PORTVERSION=	2.48
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CGI utility suite - makes powerful application writing fun and easy

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-Template-Alloy>=1.004:www/p5-Template-Alloy

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/samples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
