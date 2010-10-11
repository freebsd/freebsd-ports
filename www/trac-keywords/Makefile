# New ports collection makefile for: trac-keywords
# Date created:                      December 17, 2009
# Whom:                              Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	keywords
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	trackeywordsplugin-r${REL}

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	A plugin for using pre-configured keywords

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=	2.5+
USE_ZIP=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TracKeywordsPlugin
PYDISTUTILS_NOEGGINFO=	yes
WRKSRC=		${WRKDIR}/trackeywordsplugin/0.11
REL=		7273
PLIST_FILES=	${PYTHON_SITELIBDIR:S;${LOCALBASE}/;;}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

post-extract:
# We must fix file permissions -- ZIP file have 0000 for every file.
# Directory permissions are fine (they aren't stored inside ZIP
# file), but we set them too -- just in case.
	@${FIND} ${WRKSRC} -type f | ${XARGS} chmod 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} chmod 755
# Fix misplaced Genshi template: https://trac-hacks.org/ticket/6104
	@${MV} ${WRKDIR}/trackeywordsplugin/0.10/trackeywords/templates/keywords.html ${WRKSRC}/trackeywords/templates/
# Seems like web_ui.py was misplaced too.
	@${MV} ${WRKDIR}/trackeywordsplugin/0.10/trackeywords/web_ui.py ${WRKSRC}/trackeywords/

.include <bsd.port.mk>
