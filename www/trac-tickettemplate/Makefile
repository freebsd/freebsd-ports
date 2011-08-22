# New ports collection makefile for: trac-autocomplete
# Date created:                      August 18, 2011
# Whom:                              Eygene Ryabinkin <rea@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tickettemplate
PORTVERSION=	0.7
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/trac-${PORTNAME}/
PKGNAMEPREFIX=	trac-
DISTNAME=	trac${PORTNAME}plugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	A plugin for making ticket templates

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=	yes
USE_ZIP=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

# Python < 2.6 needs simplejson package.
.if ${PYTHON_VER} == 2.4 || ${PYTHON_VER} == 2.5
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson:${PORTSDIR}/devel/py-simplejson
.endif

USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TracTicketTemplate
PYDISTUTILS_NOEGGINFO=	yes

WRKSRC=		${WRKDIR}/trac${PORTNAME}plugin/0.11
REL=		10605
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

# We must fix file permissions -- ZIP file have 0000 for every file.
# Directory permissions are fine (they aren't stored inside ZIP
# file), but we set them too -- just in case.
post-extract:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755

# Target to generate packaging list
plist:
	@${FIND} ${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg -type f | ${SED} -e's|^${PYTHON_SITELIBDIR}/|%%PYTHON_SITELIBDIR%%/|;s|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py[[:digit:]\.]*.egg|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg|'
	@${FIND} ${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg -type d -mindepth 1 | ${SORT} -r | ${SED} -e's|^${PYTHON_SITELIBDIR}/|@dirrm %%PYTHON_SITELIBDIR%%/|;s|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py[[:digit:]\.]*.egg|/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg|'
	@[ -d ${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg ] && ${ECHO} '@dirrm %%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py%%PYTHON_VER%%.egg'

.include <bsd.port.post.mk>
