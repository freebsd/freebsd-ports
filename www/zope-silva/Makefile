# New ports collection makefile for: Silva
# Date created:		30 Dec 2003
# Whom:			Tim Middleton <x@vex.net>
#
# $FreeBSD$
#

PORTNAME=	silva
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	www zope
MASTER_SITES=	http://www.infrae.com/download/%SUBDIR%/:silva,document,metadata,sprout
MASTER_SITE_SUBDIR=	Silva/${PORTVERSION}/:silva \
			SilvaDocument/1.2/:document \
			SilvaMetadata/0.8/:metadata \
			Sprout/0.6.1/:sprout
PKGNAMEPREFIX=	zope-
DISTFILES=	Silva-${PORTVERSION}.tgz:silva \
		SilvaDocument-1.2.tgz:document \
		SilvaMetadata-0.8.tgz:metadata \
		Sprout-0.6.1.tgz:sprout

MAINTAINER=	x@Vex.Net
COMMENT=	Web application (CMS) to manage/edit structured documents

RUN_DEPENDS=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/Annotations/__init__.py:${PORTSDIR}/www/zope-annotations \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/FileSystemSite/__init__.py:${PORTSDIR}/www/zope-FileSystemSite \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/Formulator/__init__.py:${PORTSDIR}/www/zope-formulator \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/ProxyIndex/__init__.py:${PORTSDIR}/www/zope-proxyindex \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/SilvaViews/__init__.py:${PORTSDIR}/www/zope-silvaviews \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/XMLWidgets/__init__.py:${PORTSDIR}/www/zope-xmlwidgets

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=Silva

do-build:
	@${RM} ${WRKDIR}/SilvaDocument/tests/.cvsignore
	@${RM} -rf ${WRKDIR}/SilvaMetadata/Extensions/.svn
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKDIR}/
	@${CP} -R ${WRKDIR}/Silva* ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CP} -R ${WRKDIR}/Sprout ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
