# New ports collection makefile for: Squishdot
# Date created:		06 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	squishdot
PORTVERSION=	1.5.0
CATEGORIES=	www zope
MASTER_SITES=	http://squishdot.org/Download/Squishdot/ \
		http://www.zope.org/Members/chrisw/Squishdot/
DISTNAME=	Squishdot-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web-based news publishing and discussion product for Zope

RUN_DEPENDS=	${ZOPEBASEDIR}/skel/bin/zopectl.in:${PORTSDIR}/www/zope

USE_PYTHON=	yes
USE_ZOPE=	yes

# You can change this in the environment if you like.
SZOPEBASEDIR?=	www/Zope

# Don't change these
ZOPEPRODUCTNAME=	Squishdot
ZOPEPRODUCTDIR=		lib/python/Products

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}
	@${CP} -Rf ${WRKSRC}/* \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
