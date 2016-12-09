# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Text-Reflow
PORTVERSION=	1.17
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for reflowing text files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/Reflow/Reflow.so

.include <bsd.port.mk>
