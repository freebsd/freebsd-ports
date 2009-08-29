# New ports collection makefile for:	tkabber-devel
# Date created:				09 July 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	tkabber
PORTVERSION=	0.11.1.a.20090817
CATEGORIES=	net-im
MASTER_SITES=	http://wizard.volgograd.ru/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Tcl/Tk based jabber client, development version

LIB_DEPENDS=	img.1:${PORTSDIR}/graphics/libimg \
		tkXwin.1:${PORTSDIR}/x11/tkXwin
RUN_DEPENDS=	tcllib>=1.10:${PORTSDIR}/devel/tcllib \
		tcltls>=1.5.0:${PORTSDIR}/devel/tcltls \
		bwidget>=1.8.0:${PORTSDIR}/x11-toolkits/bwidget

CONFLICTS=	tkabber-[0-9]*
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_TCL_RUN=	85+
USE_TK_RUN=	85+

DESKTOP_ENTRIES=	"${PORTNAME}" \
		"${COMMENT}" \
		"" \
		"tkabber" \
		"Network;InstantMessaging;" \
		false

SUBDIRS=	emoticons ifacetk mclistbox msgs pixmaps plugins sounds \
		tclxmpp trans

OPTIONS=	ZLIB "with zlib support" off

do-install:
	${ECHO} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${WRKDIR}/tkabber.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tkabber.sh ${PREFIX}/bin/tkabber

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${SUBDIRS}" ${DATADIR})
	${HEAD} -1 ${WRKSRC}/ChangeLog > ${DATADIR}/version

	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in AUTHORS COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_ZLIB)
LIB_DEPENDS+=	ztcl[0-9]:${PORTSDIR}/devel/ztcl
.endif

.include <bsd.port.post.mk>
