# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	HTML-Adsense
PORTVERSION=	0.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Create adsense widgets easily

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor

USES=		perl5
USE_PERL5=	configure

post-patch:
	${RM} -f ${WRKSRC}/lib/HTML/._Adsense.pm

.include <bsd.port.mk>
