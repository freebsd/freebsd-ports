# New ports collection makefile for:	zope-cmftransforms
# Date created:				20 Mar 2004
# Whom:					Filippo Natali
#
# $FreeBSD$
#

PORTNAME=	cmftransforms
PORTVERSION=	1.0.3
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	archetypes
PKGNAMEPREFIX=	zope-
DISTNAME=	PortalTransforms-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	filippo@widestore.net
COMMENT=	CMFTransforms product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf \
		pdftohtml:${PORTSDIR}/textproc/pdftohtml \
		lynx:${PORTSDIR}/www/lynx \
		${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	PortalTransforms

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}-${PORTVERSION}/${ZOPEPRODUCTNAME}

OPTIONS=	WV "Add wv support" off \
		TIDY "Add tidy support" off \
		UNRTF "Add unrtf support" off \
		XLHTML "Add xlhtml support" off

.include <bsd.port.pre.mk>

.if defined(WITH_WV)
RUN_DEPENDS+=	wvHtml:${PORTSDIR}/textproc/wv
.endif

.if defined(WITH_TIDY)
RUN_DEPENDS+=	tidy:${PORTSDIR}/www/tidy
.endif

.if defined(WITH_UNRTF)
RUN_DEPENDS+=	unrtf:${PORTSDIR}/textproc/unrtf
.endif

.if defined(WITH_XLHTML)
RUN_DEPENDS+=	xlhtml:${PORTSDIR}/textproc/xlhtml
.endif

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
