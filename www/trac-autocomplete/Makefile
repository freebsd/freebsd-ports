# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	autocomplete
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	autocompleteusersplugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for autocompletion of user names in ticket fields

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=	2
USES=		zip
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	AutocompleteUsers
PYDISTUTILS_NOEGGINFO=	yes
WRKSRC=		${WRKDIR}/autocompleteusersplugin/0.11
REL=		8451

# Target to generate packaging list
plist:
	@${FIND} ${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg -type f | ${SED} -e's|^${PYTHON_SITELIBDIR}/|%%PYTHON_SITELIBDIR%%/|;s|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py[[:digit:]\.]*.egg/|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg/|'
	@${FIND} ${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg -type d -mindepth 1 | ${SORT} -r | ${SED} -e's|^${PYTHON_SITELIBDIR}/|@dirrm %%PYTHON_SITELIBDIR%%/|;s|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py[[:digit:]\.]*.egg/|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg/|'
	@${ECHO} '@dirrm %%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg'

.include <bsd.port.mk>
