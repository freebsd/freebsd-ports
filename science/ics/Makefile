# New ports collection makefile for:	ics
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ics
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://rd.edf.com/fichiers/fckeditor/File/EDF%20RD/Code_Saturne/Fichiers/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Graphical User Interface

RUN_DEPENDS=	${LOCALBASE}/lib/Tix8.4.3/Tix.tcl:${PORTSDIR}/x11-toolkits/tix \
		${CS_HOME}/bin/info_cs:${PORTSDIR}/science/ncs	\
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

NO_BUILD=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
REINPLACE_ARGS=	-i ""

PATHCS=		${PREFIX}/Saturne
CS_HOME=	${LOCALBASE}/Saturne/Noyau/ncs
ICS_HOME=	${PATHCS}/Interface/ics
PLIST_SUB=	ICS=Saturne/Interface/ics

TB=		archive clean

pre-configure:
.for tb in ${TB}
	${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/toolbin/${tb}
.endfor

do-install:
	${MKDIR} ${ICS_HOME}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${ICS_HOME})
.for sc in ics.py testSuite.py
	${CHMOD} a+x ${WRKSRC}/${sc}
	${INSTALL_SCRIPT} ${WRKSRC}/${sc} ${ICS_HOME}
.endfor
.for sc in ${TB:S|^|toolbin/|}
	${CHMOD} a+x ${WRKSRC}/${sc}
	${INSTALL_SCRIPT} ${WRKSRC}/${sc} ${ICS_HOME}/toolbin
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${ICS_HOME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${ICS_HOME}

.include <bsd.port.mk>
