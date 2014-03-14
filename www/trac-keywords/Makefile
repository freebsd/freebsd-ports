# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	keywords
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	trackeywordsplugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for using pre-configured keywords

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=	2
USES=		zip
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracKeywordsPlugin
WRKSRC=			${WRKDIR}/trackeywordsplugin/0.11
REL=			7273
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

post-extract:
# Fix misplaced Genshi template: https://trac-hacks.org/ticket/6104
	@${MV} ${WRKDIR}/trackeywordsplugin/0.10/trackeywords/templates/keywords.html ${WRKSRC}/trackeywords/templates/
# Seems like web_ui.py was misplaced too.
	@${MV} ${WRKDIR}/trackeywordsplugin/0.10/trackeywords/web_ui.py ${WRKSRC}/trackeywords/

.include <bsd.port.mk>
