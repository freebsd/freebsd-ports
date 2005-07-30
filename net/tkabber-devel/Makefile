# New ports collection makefile for:	tkabber-devel
# Date created:				09 July 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	tkabber
PORTVERSION=	0.9.8.a.20050621
CATEGORIES=	net
MASTER_SITES=	http://neva.vlink.ru/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dsh@vlink.ru
COMMENT=	Tcl/Tk based jabber client, development version

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/lib/tcllib1.7/pkgIndex.tcl:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

CONFLICTS=	tkabber-[0-9]*
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes

SUBDIRS=	aniemoteicons emoticons-tkabber ifaceck ifacetk plugins \
		jabberlib-tclxml pixmaps sounds textundo msgs mclistbox-1.02

do-install:
	${ECHO} -e "#!/bin/sh\nexec wish8.4 ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${WRKDIR}/tkabber.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tkabber.sh ${PREFIX}/bin/tkabber

	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${DATADIR}/
.for i in ${SUBDIRS}
	${CP} -R ${WRKSRC}/${i} ${DATADIR}/
.endfor

	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in AUTHORS COPYING ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
