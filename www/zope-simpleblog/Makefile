# New ports collection makefile for:	zope-simpleblog
# Date created:				05 October 2004
# Whom:					saturnero@gufi.org
#
# $FreeBSD$
#

PORTNAME=	simpleblog
PORTVERSION=	1.2.1
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	collective
PKGNAMEPREFIX=	zope-
DISTNAME=	SimpleBlog${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	saturnero@gufi.org
COMMENT=	SimpleBlog is an easy to use Plone based weblog application

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFPlone/__init__.py:${PORTSDIR}/www/plone \
		${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/Archetypes/__init__.py:${PORTSDIR}/www/zope-archetypes

WRKSRC=${WRKDIR}
USE_ZOPE=	yes
USE_PYTHON=	yes
MODULES=	SimpleBlog
PLIST=		${WRKDIR}/pkg-plist

do-build:
	-@for m in ${MODULES}; do \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/$$m; \
	done

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@for m in ${MODULES}; do \
		if [ ! -f ${ZOPEBASEDIR}/Products/$${m}/__init__.py ]; then \
			cd ${WRKSRC}; \
			for i in `${FIND} $${m} -type f`; do \
				${ECHO_CMD} %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
			done; \
			for i in `${FIND} -d $${m} -type d`; do \
				${ECHO_CMD} @dirrm %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
			done; \
		fi;\
	done

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@(cd ${WRKSRC} && ${CP} -R ${MODULES} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR})

.include <bsd.port.mk>
