# New ports collection makefile for:	zope-cmftransforms
# Date created:				20 Mar 2004
# Whom:					Filippo Natali
#
# $FreeBSD$
#

PORTNAME=	portaltransforms
PORTVERSION=	1.3.2
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	archetypes
PKGNAMEPREFIX=	zope-
DISTNAME=	PortalTransforms-${PORTVERSION}-4
EXTRACT_SUFX=	.tgz

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	PortalTransforms product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf \
		pdftohtml:${PORTSDIR}/textproc/pdftohtml \
		lynx:${PORTSDIR}/www/lynx \
		${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils

BROKEN=		Broken dependency
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	PortalTransforms
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
PLIST=		${WRKDIR}/pkg-plist

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

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} && \
	for f in `${FIND} ${ZOPEPRODUCTNAME} -type f`; do \
		${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${ZOPEPRODUCTNAME} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEPRODUCTDIR%%/$${d} >> ${PLIST}; \
	done; \

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
