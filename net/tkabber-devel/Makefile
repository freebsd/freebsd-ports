# New ports collection makefile for:	tkabber
# Date created:				22 October 2003
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	tkabber
PORTVERSION=	0.9.6b
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/tkabber/
DISTNAME=	tkabber-0.9.6beta

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	Tcl/Tk based jabber client

TCLLIBVER!=	${MAKE} -C ${.CURDIR}/../../devel/tcllib -V PORTVERSION
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/lib/tcllib${TCLLIBVER}/pkgIndex.tcl:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes

SUBDIRS = emoticons-tkabber plugins jabberlib-tclxml pixmaps \
		sounds textundo aniemoteicons msgs mclistbox-1.02

do-install:
	${ECHO} -e "#!/bin/sh\nexec wish8.4 ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${PREFIX}/bin/tkabber
	${CHMOD} +x ${PREFIX}/bin/tkabber
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${WRKSRC}/*.xrdb ${DATADIR}
.for i in ${SUBDIRS}
	${CP} -R ${WRKSRC}/${i} ${DATADIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in tkabber.html tkabber.xml
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
