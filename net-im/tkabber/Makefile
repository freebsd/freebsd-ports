# New ports collection makefile for:	tkabber
# Date created:				22 October 2003
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	tkabber
PORTVERSION=	0.10.0
CATEGORIES=	net-im
MASTER_SITES=	http://files.jabber.ru/tkabber/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Tcl/Tk based jabber client

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes

SUBDIRS=	contrib doc emoticons examples ifacetk jabberlib-tclxml mclistbox \
		msgs pixmaps plugins sounds trans

do-install:
	${ECHO} -e "#!/bin/sh\nexec wish8.4 ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${PREFIX}/bin/tkabber
	${CHMOD} +x ${PREFIX}/bin/tkabber
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${DATADIR}
.for i in ${SUBDIRS}
	${CP} -R ${WRKSRC}/${i} ${DATADIR}
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in tkabber.html tkabber.xml
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
