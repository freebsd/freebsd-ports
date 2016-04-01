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

RUN_DEPENDS=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11

USES=		python
USE_PYTHON=	distutils autoplist

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
