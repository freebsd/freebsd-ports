# New ports collection makefile for: Silva
# Date created:		30 Dec 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	silva
PORTVERSION=	0.9.3b1
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/infrae/%SUBDIR%/:silva,document,metadata
MASTER_SITE_SUBDIR=	Silva/Silva-${PORTVERSION}/:silva \
			SilvaDocument/SilvaDocument-0.9.3b1/:document \
			SilvaMetadata/SilvaMetadata-0.7.4/:metadata
PKGNAMEPREFIX=	zope-
DISTFILES=	Silva-${PORTVERSION}.tgz:silva \
		SilvaDocument-0.9.3b1.tgz:document \
		SilvaMetadata-0.7.4.tgz:metadata

MAINTAINER=	x@Vex.Net
COMMENT=	Web application to manage/edit structured documents

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

# yes, some of us are running zope on python 2.3
#PYTHON_VERSION=	python2.3

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
CPIO=		cpio --quiet -pdum -R

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}

do-install:
	@${CHMOD} -R og+rX ${WRKDIR}/
	@${RM} -rf ${WRKDIR}/SilvaMetadata/Extensions/.svn
	@ cd ${WRKDIR} && ${FIND} Silva* \
	  | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
