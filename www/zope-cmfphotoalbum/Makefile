# New ports collection makefile for:	zope-cmfphotoalbum
# Date created:			6 December 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	cmfphotoalbum
PORTVERSION=	0.4.r2
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	collective
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFPhotoAlbum-0.4rc2

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	CMFPhotoAlbum product for Zope/CMF

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/CMFPhoto/Photo.py:${PORTSDIR}/www/zope-cmfphoto \
				${LOCALBASE}/${SZOPEBASEDIR}/lib/python/Products/BTreeFolder2/BTreeFolder2.py:${PORTSDIR}/www/zope-btreefolder2

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=		${WRKDIR}/CMFPhotoAlbum

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/Extensions/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/skins/photoalbum_scripts/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
