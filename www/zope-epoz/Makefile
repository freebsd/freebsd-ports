# New ports collection makefile for:	zope-epoz
# Date created:				11 Feb 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	epoz
PORTVERSION=	0.8.0
CATEGORIES=	www zope
MASTER_SITES=	http://mjablonski.zope.de/Epoz/releases/
PKGNAMEPREFIX=	zope-
DISTNAME=	Epoz-${PORTVERSION}

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Epoz product for Zope/CMF

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/Epoz

RUN_DEPENDS+=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFCore/__init__.py:${PORTSDIR}/www/zope-cmf

PRODUCTNAME=	Epoz

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} ;\
	for f in `${FIND} ${PRODUCTNAME} -type f`; do \
		${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${PRODUCTNAME} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEPRODUCTDIR%%/$${d} >> ${PLIST}; \
	done; \

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
