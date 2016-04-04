# $FreeBSD$

PORTNAME=	wikitopdf
PORTVERSION=	2.2.2
PORTREVISION=	6
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to generate PDF documents from the Wiki

RUN_DEPENDS+=	htmldoc:textproc/htmldoc \
		tracd:www/trac

USES=		python:2
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/${PORTNAME}plugin

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
