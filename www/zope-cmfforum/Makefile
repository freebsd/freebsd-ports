# New ports collection makefile for: zope-cmfforum
# Date created:		18 Jan 2003
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	cmfforum
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	SF/collective/CMFForum/${PORTVERSION}
PKGNAMEPREFIX=	zope-
DISTNAME=	CMFForum-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A forum for ZOPE CMF with file attachments

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=		${WRKDIR}/CMFForum

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
