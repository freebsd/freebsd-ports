# New ports collection makefile for: trac-autocomplete
# Date created:                      December 16, 2009
# Whom:                              Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	datefield
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	datefieldplugin-r${REL}

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	A plugin for creating date fields

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=	2.5+
USE_ZIP=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TracDateField
PYDISTUTILS_NOEGGINFO=	yes
WRKSRC=		${WRKDIR}/datefieldplugin/0.11
REL=		7267
PLIST_FILES=	${PYTHON_SITELIBDIR:S;${LOCALBASE}/;;}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

# We must fix file permissions -- ZIP file have 0000 for every file.
# Directory permissions are fine (they aren't stored inside ZIP
# file), but we set them too -- just in case.
post-extract:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755

.include <bsd.port.mk>
