# New ports collection makefile for: trac-autocomplete
# Date created:                      December 07, 2009
# Whom:                              Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	autocomplete
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	autocompleteusersplugin-r${REL}

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	A plugin for autocompletion of user names in ticket fields

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=	2.5+
USE_ZIP=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	AutocompleteUsers
PYDISTUTILS_NOEGGINFO=	yes
WRKSRC=		${WRKDIR}/autocompleteusersplugin/0.11
REL=		7227
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

# We must fix file permissions -- ZIP file have 0000 for every file.
# Directory permissions are fine (they aren't stored inside ZIP
# file), but we set them too -- just in case.
post-extract:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755

# Target to generate packaging list
plist:
	@${FIND} ${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg -type f | ${SED} -e's|^${PYTHON_SITELIBDIR}/|%%PYTHON_SITELIBDIR%%/|;s|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py[[:digit:]\.]*.egg/|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg/|'
	@${FIND} ${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg -type d -mindepth 1 | ${SORT} -r | ${SED} -e's|^${PYTHON_SITELIBDIR}/|@dirrm %%PYTHON_SITELIBDIR%%/|;s|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py[[:digit:]\.]*.egg/|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg/|'
	@${ECHO} '@dirrm %%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg'

.include <bsd.port.mk>
