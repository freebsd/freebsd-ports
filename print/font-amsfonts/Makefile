# Created by: hrs
# $FreeBSD$

PORTNAME=	amsfonts
PORTVERSION=	3.02
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	LOCAL/hrs
PKGNAMEPREFIX=	font-
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Computer Modern and standard fonts for TeX

USES=		fonts
NO_BUILD=	yes

FONTSDIR=	${PREFIX}/share/fonts/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
