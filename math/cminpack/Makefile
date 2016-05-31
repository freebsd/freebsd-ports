# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	cminpack
PORTVERSION=	1.3.5
CATEGORIES=	math
MASTER_SITES=	GH

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Solving nonlinear equations and nonlinear least squares problems

LICENSE_FILE=	${WRKSRC}/CopyrightMINPACK.txt

USES=		cmake:outsource

USE_GITHUB=	yes
GH_PROJECT=	cminpack
GH_ACCOUNT=	devernay
GH_TAGNAME=	e89f19c

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "*.[ch] testdata" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
