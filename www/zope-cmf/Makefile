# New ports collection makefile for: Zope-PTK
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	zope-ptk
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Products/PTK/
DISTNAME=	ZopePTK-${PORTVERSION}-complete

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

DIST_SUBDIR=	zope

PKGMESSAGE=	${WRKDIR}/.message

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=
ZOPEPRODUCTDIR=		lib/python/Products

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}

do-install:
	@${CHMOD} -R og+rX ${WRKSRC}/${ZOPEPRODUCTDIR}/
	@#
	@${RM} -Rf ${WRKSRC}/${ZOPEPRODUCTDIR}/DemoPortal
	@${CP} -R ${WRKSRC}/${ZOPEPRODUCTDIR}/ \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@#
	@${CP} ${WRKSRC}/${ZOPEPRODUCTDIR}/PTKDemo/DemoPortal.zexp \
		${ZOPEBASEDIR}/import/
	@#
	@perl -pe 's#%%PREFIX%%#${PREFIX}#' \
		pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
