# New ports collection makefile for:	ics
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ics
PORTVERSION=	1.1.l
CATEGORIES=	science
MASTER_SITES=	http://www.edf.fr/html/RetD/livraison_saturne_${REL_DATE}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Graphical User Interface

LIB_DEPENDS=	tix8184:${PORTSDIR}/x11-toolkits/tix
RUN_DEPENDS=	${CS_HOME}/bin/info_cs:${PORTSDIR}/science/ncs	\
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

REL_DATE=	070305

NO_BUILD=	yes
USE_PYTHON=	yes

PATHCS=		${PREFIX}/Saturne
CS_HOME=	${LOCALBASE}/Saturne/Noyau/ncs
ICS_HOME=	${PATHCS}/Interface/ics
PLIST_SUB=	ICS=Saturne/Interface/ics

do-install:
	${MKDIR} ${ICS_HOME}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${ICS_HOME})
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${ICS_HOME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${ICS_HOME}

.include <bsd.port.mk>
