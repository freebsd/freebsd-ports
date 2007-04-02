# New ports collection makefile for:	tkabber-devel
# Date created:				09 July 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	tkabber
PORTVERSION=	0.9.9.a.20070325
CATEGORIES=	net-im
MASTER_SITES=	http://ports.internal.vlink.ru/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dsh@vlink.ru
COMMENT=	Tcl/Tk based jabber client, development version

LIB_DEPENDS=	img.1:${PORTSDIR}/graphics/libimg \
		tkXwin.1:${PORTSDIR}/x11/tkXwin
RUN_DEPENDS=	${LOCALBASE}/lib/tcllib1.9/pkgIndex.tcl:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

CONFLICTS=	tkabber-[0-9]*
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_TCL_RUN=	yes
USE_TK_RUN=	yes

SUBDIRS=	emoticons ifacetk jabberlib-tclxml mclistbox msgs pixmaps \
		plugins sounds trans

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
