# New ports collection makefile for:	zope-validation
# Date created:				06 Oct 2004
# Whom:					Filippo Natali
#
# $FreeBSD$
#

PORTNAME=	validation
PORTVERSION=	1.3.0
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	archetypes
PKGNAMEPREFIX=	zope-
DISTNAME=	${PORTNAME}-${PORTVERSION}-8
EXTRACT_SUFX=	.tgz

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	Validation product for Zope

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=	${WRKDIR}/${PORTNAME}
PLIST=	${WRKDIR}/pkg-plist

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
