# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-PDF
PORTVERSION=	0.31
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PDF manipulation module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Text/PDF/examples
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Text/PDF/examples

.include <bsd.port.mk>
