# New ports collection makefile for:	zope-cmfphotoalbum
# Date created:			6 December 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	cmfphotoalbum
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	SF/collective/CMFPhotoAlbum/CMFPhotoAlbum-${PORTVERSION}.0
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFPhotoAlbum-${PORTVERSION}.0

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	CMFPhotoAlbum product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFPhoto/Photo.py:${PORTSDIR}/www/zope-cmfphoto \
				${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/BTreeFolder2/BTreeFolder2.py:${PORTSDIR}/www/zope-btreefolder2

NO_PACKAGE=	Double python dependency

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=CMFPhotoAlbum

PLIST=		${WRKSRC}/pkg-plist
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/Extensions/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/skins/photoalbum_scripts/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} && \
	for f in `${FIND} ${ZOPEPRODUCTNAME} -type f`; do \
		${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${ZOPEPRODUCTNAME} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEPRODUCTDIR%%/$${d} >> ${PLIST}; \
	done;

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
