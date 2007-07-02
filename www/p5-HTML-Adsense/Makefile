# New ports collection makefile for:	p5-HTML-Adsense
# Date created:		2007-06-29
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Adsense
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Create adsense widgets easily

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor

PERL_CONFIGURE=	yes

MAN3=		HTML::Adsense.3

post-patch:
	${RM} -f ${WRKSRC}/lib/HTML/._Adsense.pm

.include <bsd.port.mk>
