# New ports collection makefile for:	zope-generator
# Date created:				06 Oct 2004
# Whom:					Filippo Natali
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	1.3.1
CATEGORIES=	www zope
MASTER_SITES=	SF/archetypes/Archetypes/1.3.4
PKGNAMEPREFIX=	zope-
DISTNAME=	${PORTNAME}-${PORTVERSION}-final01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generator product for Zope

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=	${WRKDIR}/${PORTNAME}
PLIST=	${WRKDIR}/pkg-plist

CONFLICTS=	plone[0-9]*-[0-9]*

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} && \
	for f in `${FIND} ${PORTNAME} -type f`; do \
		${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${PORTNAME} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEPRODUCTDIR%%/$${d} >> ${PLIST}; \
	done; \

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${ECHO} Restart Zope to complete installation of ${PORTNAME}
.endif

.include <bsd.port.mk>
