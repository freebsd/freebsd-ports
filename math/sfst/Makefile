# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	sfst
PORTVERSION=	1.4.6h
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.cis.uni-muenchen.de/~schmid/tools/SFST/data/
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A toolbox for the implementation of morphological analysers

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME:tu}/src
INSTALL_TARGET=	install maninstall libinstall
USES=		gmake readline
USE_LDCONFIG=	yes

.include <bsd.port.mk>
