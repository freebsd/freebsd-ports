# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	sguil-client
PORTVERSION=	0.8.0
CATEGORIES=	security
MASTER_SITES=	SF/sguil/sguil/sguil-${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Sguil is a network security monitoring program

LIB_DEPENDS=	tls:${PORTSDIR}/devel/tcltls
RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:${PORTSDIR}/lang/tclX \
		${LOCALBASE}/lib/iwidgets/iwidgets.tcl:${PORTSDIR}/x11-toolkits/iwidgets \
		gpg2:${PORTSDIR}/security/gnupg

LICENSE_NAME=	QPLv1.0 COPYRIGHT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.QPL
LICENSE_PERMS=	auto-accept
LICENSE_FILE=	${WRKSRC}/client/lib/tablelist4.1/COPYRIGHT.txt
LICENSE_PERMS=	auto-accept

OPTIONS_DEFINE=	AUDIO SANCP WIRESHARK
AUDIO_DESC=	Install Festival Speech Synthesis
SANCP_DESC=	Use sancp
WIRESHARK_DESC=	Install wireshark

NO_BUILD=	yes
USE_TK_WRAPPER=	yes
USE_TCL=	yes
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
SUB_LIST=	SGUILDIR=${SGUILDIR}
SUB_FILES=	pkg-message
PLIST_SUB=	SGUILDIR=${SGUILDIR}
SGUILDIR?=	sguil-client

PORTDOCS1=	README
PORTDOCS2=	CHANGES FAQ INSTALL INSTALL.openbsd OPENSSL.README TODO UPGRADE USAGE sguildb.dia

LIBFILES=	SguilUtil.tcl dkffont.tcl email17.tcl extdata.tcl sellib.tcl sancp.tcl \
		 sound.tcl guilib.tcl qrybuild.tcl qrylib.tcl report.tcl stdquery.tcl whois.tcl

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if $(PORT_OPTIONS:MAUDIO)
RUN_DEPENDS+=	festival:${PORTSDIR}/audio/festival
.endif

.if ${PORT_OPTIONS:MSANCP}
RUN_DEPENDS+=	sancp:${PORTSDIR}/security/sancp
.endif

.if $(PORT_OPTIONS:MWIRESHARK)
RUN_DEPENDS+=	wireshark:${PORTSDIR}/net/wireshark
.endif

do-install:
	@${MKDIR} ${PREFIX}/bin/${SGUILDIR}
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/client/sguil.tk \
		${PREFIX}/bin/${SGUILDIR}/sguil.tk
.for f in sguil.conf
	${INSTALL_DATA} ${WRKSRC}/client/${f} \
		${PREFIX}/etc/${f}-sample
.endfor
.for f in ${LIBFILES}
	@${MKDIR} ${PREFIX}/bin/${SGUILDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/client/lib/${f} ${PREFIX}/bin/${SGUILDIR}/lib/${f}
.endfor
.for f in sguil_logo_h.gif
	@${MKDIR} ${PREFIX}/bin/${SGUILDIR}/images
	${INSTALL_DATA} ${WRKSRC}/client/lib/images/${f} \
		${PREFIX}/bin/${SGUILDIR}/images/${f}
.endfor

	(cd ${WRKSRC}/client/lib/tablelist4.1 && ${COPYTREE_SHARE} \* \
		${PREFIX}/bin/${SGUILDIR}/lib/tablelist4.1/)

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS1} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS2} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
