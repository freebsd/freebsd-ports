# New ports collection makefile for: ZNavigator
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	znavigator
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/jonas/ZNavigator/
DISTNAME=	${ZOPEPRODUCTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Zope product to simplify the construction of navigation bars

USE_PYTHON=	YES
USE_ZOPE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/lib/python

# Don't change these
ZOPEPRODUCTNAME=	ZNavigator
ZOPEPRODUCTSRC=		${WRKSRC}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

PKGMESSAGE=	${WRKDIR}/.pkg-message

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/
	@${CP} -Rf ${ZOPEPRODUCTSRC}/* \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/
	@${CP} ${ZOPEPRODUCTSRC}/demo/navigator_demo.zexp \
		${ZOPEBASEDIR}/import
	@${SED} -e \
		's#%%PREFIX%%#${PREFIX}#' ${FILESDIR}/MESSAGE > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
