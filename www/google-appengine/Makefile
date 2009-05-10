# New ports collection makefile for:	google-appengine
# Date created:		2008-04-09
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	google-appengine
PORTVERSION=	1.2.2
PORTREVISION=	0
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${PORTNAME:S|-|_|}_${PORTVERSION}.zip
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-docs-${GAEDOCSREL}.zip
.endif

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Development tools for Google App Engine (SDK)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_2:${PORTSDIR}/graphics/py-imaging

PROJECTHOST=	googleappengine

NO_BUILD=	yes

USE_PYTHON=	2.5+
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/${PORTNAME:S,-,_,}

FIND_FILES=	${WRKSRC} -type f -name "*.py" -print0
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)

LN_OPTS=	-s

XARGS_ARGS=	-0
REINPLACE_ARGS=	-i.bak -e 's,/usr/bin/env python,&${PYTHON_VER},'

GAEDATADIR=	google lib new_project_template templates tools
GAEDOCSREL=	20090422

post-patch:
	@${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${GAEDATADIR}" ${DATADIR} "-not -path './demos*' -and -mindepth 1"
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/README ${DOCSDIR}
	cd ${WRKDIR}/google-appengine-docs-${GAEDOCSREL} && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/dev_appserver.py ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/appcfg.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DATADIR}
	${LN} ${LN_OPTS} ${DATADIR}/dev_appserver.py ${PREFIX}/bin/dev_appserver.py
	${LN} ${LN_OPTS} ${DATADIR}/appcfg.py ${PREFIX}/bin/appcfg.py

.include <bsd.port.mk>
