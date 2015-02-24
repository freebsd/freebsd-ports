# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	cminpack
PORTVERSION=	1.3.4
CATEGORIES=	math
MASTER_SITES=	http://devernay.free.fr/hacks/${PORTNAME}/

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Solving nonlinear equations and nonlinear least squares problems

USES=		cmake:outsource

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "*.[ch] testdata" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
