# New ports collection makefile for:	ics
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ics
PORTVERSION=	1.3.2
CATEGORIES=	science
MASTER_SITES=	http://rd.edf.com/fichiers/fckeditor/File/EDF%20RD/Code_Saturne/Fichiers/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Graphical User Interface

LIB_DEPENDS=	tix8184:${PORTSDIR}/x11-toolkits/tix
RUN_DEPENDS=	${CS_HOME}/bin/info_cs:${PORTSDIR}/science/ncs	\
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

NO_BUILD=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

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
