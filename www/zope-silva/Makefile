# New ports collection makefile for: Silva
# Date created:		30 Dec 2003
# Whom:			Tim Middleton
#
# $FreeBSD$
#

PORTNAME=	silva
PORTVERSION=	0.9.3.6
PORTEPOCH=	1
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/infrae/%SUBDIR%/:silva,document,metadata
MASTER_SITE_SUBDIR=	Silva/Silva-${PORTVERSION}/:silva \
			SilvaDocument/SilvaDocument-0.9.3.6/:document \
			SilvaMetadata/SilvaMetadata-0.7.5/:metadata
PKGNAMEPREFIX=	zope-
DISTFILES=	Silva-${PORTVERSION}.tgz:silva \
		SilvaDocument-0.9.3.6.tgz:document \
		SilvaMetadata-0.7.5.tgz:metadata

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

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKDIR}/
	@${CP} -R ${WRKDIR}/Silva* ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
