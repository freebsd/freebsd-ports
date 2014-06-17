# $FreeBSD$

PORTNAME=	wikitopdf
PORTVERSION=	2.2.2
PORTREVISION=	6
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to generate PDF documents from the Wiki

RUN_DEPENDS+=	htmldoc:${PORTSDIR}/textproc/htmldoc \
		tracd:${PORTSDIR}/www/trac

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
WRKSRC=			${WRKDIR}/${PORTNAME}plugin

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
