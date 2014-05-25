# $FreeBSD$

PORTNAME=	twig
PORTVERSION=	1.13.1
CATEGORIES=	www
MASTER_SITES=  	http://pear.twig-project.org/get/
PKGNAMESUFFIX=	-php
DISTNAME=	Twig-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@michael-fausten.de
COMMENT=	Fast, secure, flexible and modern template engine for PHP

NO_BUILD=	yes
USE_PHP=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
