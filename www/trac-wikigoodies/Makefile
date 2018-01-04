# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	wikigoodies
PORTVERSION=	0.3.3522
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin.${PORTVERSION}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Plugin for Trac which extends the Wiki with some goodies

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
