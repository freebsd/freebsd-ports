# New ports collection makefile for: XMLMethods
# Date created:		02 Aug 2004
# Whom:			Alexander Leidinger
#
# $FreeBSD$
#

PORTNAME=	xmlmethods
PORTVERSION=	1.0.0
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	zopexmlmethods
PKGNAMEPREFIX=	zope-
DISTNAME=	zopexmlmethods-${PORTVERSION:C/\./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides methods to apply to Zope objects for XML/XSLT processing

LIB_DEPENDS=	xslt:${PORTSDIR}/textproc/libxslt

USE_PYTHON=	yes
USE_ZOPE=	yes
USE_ZIP=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=ZopeXMLMethods

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO_FLAGS=	--quiet -pdum -R

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${CHMOD} -R a+r,go-w ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} $CPIO_FLAGS} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
