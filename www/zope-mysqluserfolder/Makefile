# New ports collection makefile for: mysqlUserFolder
# Date created:		02 Aug 2004
# Whom:			Alexander Leidinger
#
# $FreeBSD$
#

PORTNAME=	mysqluserfolder
PORTVERSION=	1.0.4
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/vladap/${ZOPEPRODUCTNAME}/release-${PORTVERSION}/
PKGNAMEPREFIX=	zope-
DISTNAME=	${ZOPEPRODUCTNAME}-${PORTVERSION}

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	A Zope user folder which uses MySQL database to store user information

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb

BROKEN=		Incomplete pkg-plist

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=mysqlUserFolder

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}
CPIO_FLAGS=	--quiet -pdum -R

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${CHMOD} -R og+rX ${WRKSRC}/
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} ${CPIO_FLAGS} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
