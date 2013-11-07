# $FreeBSD$

PORTNAME=	HTML-SuperForm
PORTVERSION=	1.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JALLWINE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML form generator

USES=		perl5
USE_PERL5=	configure

WRKSRC=	${WRKDIR}/${PORTNAME}

post-extract:
	@${RM} ${WRKSRC}/lib/HTML/SuperForm.pm.orig

.include <bsd.port.mk>
