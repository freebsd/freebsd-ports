# New ports collection makefile for:	zope-groupuserfolder
# Date created:			21 January 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	groupuserfolder
PORTVERSION=	3.1.1
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	collective
PKGNAMEPREFIX=	zope-
DISTNAME=	GroupUserFolder-${PORTVERSION}

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	GroupUserFolder product for Zope

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

EXTRACT_CMD=	tar
EXTRACT_BEFORE_ARGS=	-zxvf
EXTRACT_AFTER_ARGS=	--exclude debian
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/GroupUserFolder

PRODUCTNAME=	GroupUserFolder

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} ;\
	for f in `${FIND} ${PRODUCTNAME} -type f`; do \
		${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${PRODUCTNAME} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEPRODUCTDIR%%/$${d} >> ${PLIST}; \
	done;

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
