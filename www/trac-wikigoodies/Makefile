# New ports collection makefile for:	trac-wikigoodies
# Date created:				Fri 01 May 2009
# Whom:					Alexey V. Degtyarev <alexey@renatasystems.org>
#
# $FreeBSD$
#

PORTNAME=	wikigoodies
PORTVERSION=	0.3.3522
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin.${PORTVERSION}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Plugin for Trac which extends the Wiki with some goodies

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PYDISTUTILS_PKGNAME=	TracWikiGoodies
PYDISTUTILS_PKGVERSION=	0.11.${PORTVERSION:R}dev
PYDISTUTILS_NOEGGINFO=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION:R} \
		PYTHONVERSION=${_PYTHON_VERSION}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
