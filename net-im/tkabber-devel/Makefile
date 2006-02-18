# New ports collection makefile for:	tkabber-devel
# Date created:				09 July 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	tkabber
PORTVERSION=	0.9.8.a.20060209
CATEGORIES=	net-im
MASTER_SITES=	http://ports.internal.vlink.ru/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dsh@vlink.ru
COMMENT=	Tcl/Tk based jabber client, development version

LIB_DEPENDS=	img.1:${PORTSDIR}/graphics/libimg \
		tkXwin.1:${PORTSDIR}/x11/tkXwin
RUN_DEPENDS=	${LOCALBASE}/lib/tcllib1.7/pkgIndex.tcl:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

CONFLICTS=	tkabber-[0-9]*
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_TCL=	yes
USE_TK=		yes

SUBDIRS=	aniemoteicons emoticons-tkabber ifaceck ifacetk plugins \
		jabberlib-tclxml pixmaps sounds textundo msgs mclistbox-1.02

do-install:
	${ECHO} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${WRKDIR}/tkabber.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tkabber.sh ${PREFIX}/bin/tkabber

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DATADIR}
.for i in ${SUBDIRS}
	${CP} -R ${WRKSRC}/${i} ${DATADIR}
.endfor
	${HEAD} -1 ${WRKSRC}/ChangeLog > ${DATADIR}/version

	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}

.for i in ${DATADIR} ${EXAMPLESDIR}
	${FIND} ${i} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${i} -type f -print0 | ${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in AUTHORS COPYING ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
