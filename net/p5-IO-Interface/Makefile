# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	IO-Interface
PORTVERSION=	1.09
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for access to network card configuration information

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/IO/Interface/Interface.so

.include <bsd.port.mk>
