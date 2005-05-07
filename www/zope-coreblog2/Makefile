# New ports collection makefile for:	zope-coreblog
# Date created:				20 March 2004
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	coreblog
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	www zope
MASTER_SITES=	http://coreblog.org/junk/ \
		http://www.zope.org/Members/ats/COREBlog/COREBlog1.2/
PKGNAMEPREFIX=	zope-
DISTNAME=	COREBlog12
EXTRACT_SUFX=	.tgz

MAINTAINER=	yasi@yasi.to
COMMENT=	A Zope Blog/Weblog/Web-nikki Product

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=COREBlog

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} ;\
	for f in `${FIND} ${ZOPEPRODUCTNAME} -type f`; do \
		${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${ZOPEPRODUCTNAME} -type d`; do \
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
