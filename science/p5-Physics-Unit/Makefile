# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	Physics-Unit
PORTVERSION=	0.54
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Manipulate Physics units and dimensions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

NO_ARCH=	YES
USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/eg/ && ${COPYTREE_SHARE} '*.pl' ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
