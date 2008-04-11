# New ports collection makefile for:	zope-calendaring
# Date created:			23 January 2006
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	calendaring
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	http://www.enfoldsystems.com/Products/Open/Downloads/
PKGNAMEPREFIX=	zope-
DISTNAME=	Calendaring-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Calendar product for Plone

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:${PORTSDIR}/devel/py-dateutil \
		${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFPlone/__init__.py:${PORTSDIR}/www/plone

NO_PACKAGE=	Double python dependency

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=Calendaring

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}-${PORTVERSION}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -x skins ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKDIR}/
	@${CP} -R ${WRKSRC}/${ZOPEPRODUCTNAME}  ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
