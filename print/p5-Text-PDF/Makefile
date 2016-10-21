# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-PDF
PORTVERSION=	0.29a
PORTREVISION=	3
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	PDF manipulation module

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/pm_to_blib

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Text/PDF/examples
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Text/PDF/examples

.include <bsd.port.mk>
