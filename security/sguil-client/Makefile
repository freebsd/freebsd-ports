# New ports collection makefile for:	sguil-client
# Date created:				2 Nov 2006
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	sguil-client
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/sguil/sguil/sguil-${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Sguil is a network security monitoring program

LIB_DEPENDS=	tls:${PORTSDIR}/devel/tcltls
RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib \
		gpg2:${PORTSDIR}/security/gnupg \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:${PORTSDIR}/lang/tclX \
		${LOCALBASE}/lib/iwidgets/iwidgets.tcl:${PORTSDIR}/x11-toolkits/iwidgets

OPTIONS=	WIRESHARK "Install wireshark" off \
		AUDIO "Install Festival Speech Synthesis" off

NO_BUILD=	YES
WISH_CMD?=	wish8.4
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
SUB_LIST=	SGUILDIR=${SGUILDIR}
SUB_FILES=	pkg-message
PLIST_SUB=	SGUILDIR=${SGUILDIR} LIBDIR=${LIBDIR} IMAGEDIR=${IMAGEDIR} SCRIPTDIR=${SCRIPTDIR}
SGUILDIR?=	sguil-client
LIBDIR?=	${SGUILDIR}/lib
IMAGEDIR?=	${LIBDIR}/tablelist4.1/images
SCRIPTDIR?=	${LIBDIR}/tablelist4.1/scripts

PORTDOCS=	CHANGES FAQ INSTALL INSTALL.openbsd LICENSE.QPL \
		OPENSSL.README TODO UPGRADE USAGE sguildb.dia

LIBFILES=	SguilUtil.tcl dkffont.tcl email17.tcl extdata.tcl guilib.tcl nessusheader.html \
		qrybuild.tcl qrylib.tcl report.tcl sancp.tcl sellib.tcl sound.tcl stdquery.tcl \
		whois.tcl

IMAGES=		DarkLineDown10x9.xbm DarkLineDown12x11.xbm DarkLineDown8x7.xbm DarkLineUp10x9.xbm \
		DarkLineUp12x11.xbm DarkLineUp8x7.xbm LightLineDown10x9.xbm LightLineDown12x11.xbm \
		LightLineDown8x7.xbm LightLineUp10x9.xbm LightLineUp12x11.xbm LightLineUp8x7.xbm \
		TriangleDown10x9.xbm TriangleDown12x11.xbm TriangleDown7x4.xbm TriangleDown7x7.xbm \
		TriangleDown8x5.xbm TriangleDown8x7.xbm TriangleDown9x5.xbm TriangleUp10x9.xbm \
		TriangleUp12x11.xbm TriangleUp7x4.xbm TriangleUp7x7.xbm TriangleUp8x5.xbm \
		TriangleUp8x7.xbm TriangleUp9x5.xbm checked.xbm unchecked.xbm

SCRIPTS=	mwutil.tcl repair.tcl tablelistBind.tcl tablelistConfig.tcl tablelistEdit.tcl \
		tablelistMove.tcl tablelistSort.tcl tablelistThemes.tcl tablelistUtil.tcl \
		tablelistWidget.tcl tclIndex

.include <bsd.port.pre.mk>

.if defined(WITH_WIRESHARK)
RUN_DEPENDS+=	wireshark:${PORTSDIR}/net/wireshark
.endif

.if defined(WITH_AUDIO)
RUN_DEPENDS+=	festival:${PORTSDIR}/audio/festival
.endif

post-patch:
.for f in sguil.tk
	@${REINPLACE_CMD} -e 's:exec wish:exec ${PREFIX}/bin/${WISH_CMD}:g' \
		${WRKSRC}/client/${f}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/bin/${SGUILDIR}
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/client/sguil.tk \
		${PREFIX}/bin/${SGUILDIR}/sguil.tk
.for f in sguil.conf
	${INSTALL_DATA} ${WRKSRC}/client/${f} \
		${PREFIX}/etc/${f}-sample
.endfor
.for f in ${LIBFILES}
	@${MKDIR} ${PREFIX}/bin/${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/client/lib/${f} ${PREFIX}/bin/${LIBDIR}/${f}
.endfor
.for f in tablelist.tcl tablelistPublic.tcl COPYRIGHT.txt
	@${MKDIR} ${PREFIX}/bin/${LIBDIR}/tablelist4.1
	${INSTALL_DATA} ${WRKSRC}/client/lib/tablelist4.1/${f} \
		${PREFIX}/bin/${LIBDIR}/tablelist4.1/${f}
.endfor
.for f in ${IMAGES}
	@${MKDIR} ${PREFIX}/bin/${IMAGEDIR}
	${INSTALL_DATA} ${WRKSRC}/client/lib/tablelist4.1/images/${f} \
		${PREFIX}/bin/${IMAGEDIR}/${f}
.endfor
.for f in ${SCRIPTS}
	@${MKDIR} ${PREFIX}/bin/${SCRIPTDIR}
	${INSTALL_DATA} ${WRKSRC}/client/lib/tablelist4.1/scripts/${f} \
		${PREFIX}/bin/${SCRIPTDIR}/${f}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} \
		${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
