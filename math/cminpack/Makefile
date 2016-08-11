# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	cminpack
PORTVERSION=	1.3.5
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Solving nonlinear equations and nonlinear least squares problems

LICENSE_FILE=	${WRKSRC}/CopyrightMINPACK.txt

USES=		cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	devernay

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "*.[ch] testdata" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
