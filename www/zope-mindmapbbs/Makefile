# New ports collection makefile for:	zope-mindmapbbs
# Date created:				31 May 2004
# Whom:					HAYASHI Yasushi <yasi@yasi.to>
#
# $FreeBSD$
#

PORTNAME=	mindmapbbs
PORTVERSION=	0.3.3
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	mindmapbbs/9624
PKGNAMEPREFIX=	zope-
DISTNAME=	MindMapBBS
DIST_SUBDIR=	zope

MAINTAINER=	yasi@yasi.to
COMMENT=	A Zope product to create graphical BBS based on Mind Map

USE_PYTHON=	yes
USE_ZOPE=	yes

ZOPEPRODUCTNAME=	MindMapBBS

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} ;\
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

.include <bsd.port.mk>
