# New ports collection makefile for: trac-webadmin
# Date created:                      17 Feb 2006
# Whom:                              kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	webadmin
PORTVERSION=	0.1.1.2765
CATEGORIES=	www devel python
#MASTER_SITES=	http://projects.edgewall.com/trac/attachment/wiki/WebAdmin/TracWebAdmin-0.1.1dev_r2765-py2.4.egg.zip?format=raw
MASTER_SITES=	http://dist.bsdlab.org/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracWebAdmin-${VERSION_ID}.egg

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Web Administering plugin for trac

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

USE_ZIP=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	VERSION=${VERSION_ID}
NO_BUILD=	yes

VERSION_ID=	0.1.1dev_r2765-py2.4

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${PYTHON_SITELIBDIR}/${DISTNAME}

# --- trac.ini
# [components]
# webadmin.* = enabled
#
# ---
# % trac-admin /path/to/trac permission add user1 TRAC_ADMIN

.include <bsd.port.mk>
