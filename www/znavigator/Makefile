# New ports collection makefile for: ZNavigator
# Date created:		18 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	znavigator
PORTVERSION=	2.00
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/jonas/ZNavigator/
DISTNAME=	${ZOPEPRODUCTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

NO_BUILD=	YES
USE_PERL5=	yes
USE_REINPLACE=	yes

# You can change this in the environment if you like.
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	ZNavigator
ZOPEPRODUCTDIR=		lib/python/Products

ZOPEPRODUCTSRC=		${WRKDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

PKGMESSAGE=	${WRKDIR}/.pkg-message

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/
	@${CP} -Rf ${ZOPEPRODUCTSRC}/* \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/
	@${CP} ${ZOPEPRODUCTSRC}/demo/navigator_demo.zexp \
		${ZOPEBASEDIR}/import
	@${REINPLACE_CMD} -e \
		's#%%PREFIX%%#${PREFIX}#' ${FILESDIR}/MESSAGE > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
