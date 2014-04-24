# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	tkabber
PORTVERSION=	0.11.1.a.20100207
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://wizard.volgograd.ru/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Tcl/Tk based jabber client, development version

LIB_DEPENDS=	libtkXwin.so:${PORTSDIR}/x11/tkXwin
RUN_DEPENDS=	tcllib>=1.10:${PORTSDIR}/devel/tcllib \
		tcltls>=1.5.0:${PORTSDIR}/devel/tcltls \
		bwidget>=1.8.0:${PORTSDIR}/x11-toolkits/bwidget

CONFLICTS=	tkabber-[0-9]*
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DEPRECATED=	Unfetchable, outdated by net-im/tkabber
EXPIRATION_DATE=2014-05-23

USE_BZIP2=	yes
USES=		tk:85+,run

PORTDOCS=	*
PORTEXAMPLES=	*

DESKTOP_ENTRIES=	"${PORTNAME}" \
		"${COMMENT}" \
		"" \
		"tkabber" \
		"Network;InstantMessaging;" \
		false

SUBDIRS=	emoticons ifacetk mclistbox msgs pixmaps plugins sounds \
		tclxmpp trans

OPTIONS_DEFINE=	ZLIB

.include <bsd.port.options.mk>

do-install:
	${ECHO} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${WRKDIR}/tkabber.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tkabber.sh ${STAGEDIR}${PREFIX}/bin/tkabber

	${ECHO} -e "#!/bin/sh\nexec ${TCLSH} ${DATADIR}/tkabber-remote.tcl \
		-name tkabber-remote \"\$$@\"\n" > ${WRKDIR}/tkabber-remote.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tkabber-remote.sh ${STAGEDIR}${PREFIX}/bin/tkabber-remote

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${SUBDIRS}" ${STAGEDIR}${DATADIR})
	${HEAD} -1 ${WRKSRC}/ChangeLog > ${STAGEDIR}${DATADIR}/version

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.  for i in AUTHORS COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.  endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MZLIB}
LIB_DEPENDS+=	libztcl[0-9].so:${PORTSDIR}/devel/ztcl
.endif

.include <bsd.port.mk>
