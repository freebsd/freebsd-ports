# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	sguil-client
PORTVERSION=	0.8.0
PORTREVISION=	1
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
USES=		tk:wrapper
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
SUB_LIST=	SGUILDIR=${SGUILDIR}
SUB_FILES=	pkg-message
PLIST_SUB=	SGUILDIR=${SGUILDIR}
SGUILDIR?=	sguil-client

PORTDOCS1=	README
PORTDOCS2=	CHANGES FAQ INSTALL INSTALL.openbsd OPENSSL.README TODO UPGRADE USAGE sguildb.dia

LIBFILES=	SguilUtil.tcl dkffont.tcl email17.tcl extdata.tcl sellib.tcl sancp.tcl \
		sound.tcl guilib.tcl qrybuild.tcl qrylib.tcl report.tcl stdquery.tcl whois.tcl

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/${SGUILDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/client/sguil.tk \
		${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/sguil.tk
	${INSTALL_DATA} ${PORTDOCS1:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS2:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
.for f in sguil.conf
	${INSTALL_DATA} ${WRKSRC}/client/${f} \
		${STAGEDIR}${PREFIX}/etc/${f}-sample
.endfor
.for f in ${LIBFILES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/client/lib/${f} ${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/lib/${f}
.endfor
.for f in sguil_logo_h.gif
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/images
	${INSTALL_DATA} ${WRKSRC}/client/lib/images/${f} \
		${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/images/${f}
.endfor

	(cd ${WRKSRC}/client/lib/tablelist4.1 && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/lib/tablelist4.1/)

.include <bsd.port.mk>
