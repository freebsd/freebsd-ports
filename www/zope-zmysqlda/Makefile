# New ports collection makefile for: zope-zmysqlda
# Date created:		15 August 2001
# Whom:			Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zmysqlda
PORTVERSION=	2.0.8
CATEGORIES=	www databases zope
MASTER_SITES=	http://www.zope.org/Members/adustman/Products/ZMySQLDA/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
PKGNAMEPREFIX=	zope-
DISTNAME=	${ZOPEPRODUCTNAME}-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope \
		${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb

USE_PYTHON=	yes
DIST_SUBDIR=	zope

# You can change this in the environment if you like
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	ZMySQLDA
ZOPEPRODUCTDIR=		lib/python/Products

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
CPIO=		cpio --quiet -pdum -R

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@ cd ${WRKSRC} && find * | ${CPIO} ${BINOWN}:${BINGRP} \
	  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
