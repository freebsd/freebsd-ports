# New ports collection makefile for: Zope-PTK
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	zope-cmf
PORTVERSION=	1.3
CATEGORIES=	www zope
MASTER_SITES=	http://cmf.zope.org/download/CMF-${PORTVERSION}/
DISTNAME=	CMF-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

USE_PYTHON=	yes
DIST_SUBDIR=	zope

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=
ZOPEPRODUCTDIR=		lib/python/Products

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/CMF*

do-install:
	@${CHMOD} -R og+rX ${WRKSRC}/
.for cmfdir in Calendar Core Default Topic
	@${CP} -R ${WRKSRC}/CMF${cmfdir} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
.endfor

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
