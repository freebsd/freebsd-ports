# Created by: Alexander Timoshenko <gonzo@univ.kiev.ua>
# $FreeBSD$

PORTNAME=	tkabber
PORTVERSION=	0.11.1
CATEGORIES=	net-im
MASTER_SITES=	http://files.jabber.ru/tkabber/

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Tcl/Tk based jabber client

RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFLICTS=	tkabber-devel-*

USES=		tk:85
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes

SUBDIRS=	contrib doc emoticons examples ifacetk jabberlib mclistbox \
		msgs pixmaps plugins sounds tclxml trans

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|%%WISH%%|${WISH}|g' \
	    ${WRKSRC}/Makefile ${WRKSRC}/tkabber.tcl

do-install:
	${ECHO} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${STAGEDIR}${PREFIX}/bin/tkabber
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/tkabber
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${STAGEDIR}${DATADIR}
.for i in ${SUBDIRS}
	${CP} -R ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in tkabber.html tkabber.xml
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
