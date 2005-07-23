# New ports collection makefile for: zope-zmysqlda
# Date created:		15 August 2001
# Whom:			Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zmysqlda
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	www databases zope
MASTER_SITES=	http://www.zope.org/Members/adustman/Products/ZMySQLDA/${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
PKGNAMEPREFIX=	zope-
DISTNAME=	${ZOPEPRODUCTNAME}-${PORTVERSION}

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	MySQL Database Adapter for the Zope web application framework

RUN_DEPENDS=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	ZMySQLDA
WRKSRC=		${WRKDIR}/lib/python/Products/${ZOPEPRODUCTNAME}
CPIO_OPTIONS=	--quiet -pdum -R

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && ${FIND} * | ${CPIO} ${CPIO_OPTIONS} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
