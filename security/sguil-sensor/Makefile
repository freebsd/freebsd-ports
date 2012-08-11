# New ports collection makefile for:	sguil-sensor
# Date created:				23 Mar 2006
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	sguil-sensor
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/sguil/sguil/sguil-${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Sguil is a network security monitoring program

LIB_DEPENDS=	tls:${PORTSDIR}/devel/tcltls
RUN_DEPENDS=	snort:${PORTSDIR}/security/snort \
		barnyard2:${PORTSDIR}/security/barnyard2 \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:${PORTSDIR}/lang/tclX

OPTIONS=	SANCP "Include sancp sensor" off \
		PADS "Include pads sensor" off

NO_BUILD=	yes
USE_RC_SUBR=	example_agent pcap_agent snort_agent
TCLSH_CMD?=	tclsh8.4
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
SUB_LIST=	SGUILDIR=${SGUILDIR}
SUB_FILES=	pkg-message
PLIST_SUB=	SGUILDIR=${SGUILDIR}
SGUILDIR?=	sguil-sensor
AGENTS=		example_agent.tcl pads_agent.tcl pcap_agent.tcl sancp_agent.tcl snort_agent.tcl

PORTDOCS=	CHANGES FAQ INSTALL INSTALL.openbsd LICENSE.QPL \
		OPENSSL.README TODO UPGRADE USAGE sguildb.dia

.include <bsd.port.pre.mk>

WITH_PCRE=	true

.if defined(WITH_SANCP)
RUN_DEPENDS+=	sancp:${PORTSDIR}/security/sancp
USE_RC_SUBR+=	sancp_agent
PLIST_SUB+=	USESANCP=
.else
PLIST_SUB+=	USESANCP="@comment "
.endif

.if defined(WITH_PADS)
RUN_DEPENDS+=	pads:${PORTSDIR}/net-mgmt/pads
USE_RC_SUBR+=	pads_agent
PLIST_SUB+=	USEPADS=
.else
PLIST_SUB+=	USEPADS="@comment "
.endif

post-patch:
.for f in ${AGENTS}
	@${REINPLACE_CMD} -e 's:exec tclsh:exec ${PREFIX}/bin/${TCLSH_CMD}:g' \
		${WRKSRC}/sensor/${f}
	@${REINPLACE_CMD} -e 's:/etc/:${PREFIX}/etc/${SGUILDIR}/:g' \
		${WRKSRC}/sensor/${f}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/bin/${SGUILDIR}
	@${MKDIR} ${PREFIX}/etc/${SGUILDIR}
.for f in example_agent.tcl pcap_agent.tcl snort_agent.tcl
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/sensor/${f} \
		${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.for f in log_packets.sh
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/sensor/${f} \
		${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.for f in example_agent.conf pcap_agent.conf snort_agent.conf
	${INSTALL_DATA} ${WRKSRC}/sensor/${f} \
		${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor
.for f in log_packets.conf
	${INSTALL_DATA} ${FILESDIR}/${f} \
		${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor
.if defined(WITH_SANCP)
.for f in sancp_agent.conf
	${INSTALL_DATA} ${WRKSRC}/sensor/${f} \
		${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor
.for f in sancp.conf
	${INSTALL_DATA} ${WRKSRC}/sensor/sancp/${f} \
		${PREFIX}/etc/${f}-sample
.endfor
.for f in sancp_agent.tcl
	${INSTALL_SCRIPT} ${WRKSRC}/sensor/${f} \
		${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.endif
.if defined(WITH_PADS)
.for f in pads_agent.conf
	${INSTALL_DATA} ${WRKSRC}/sensor/${f} \
		${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor
.for f in pads_agent.tcl
	${INSTALL_SCRIPT} ${WRKSRC}/sensor/${f} \
		${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.endif
post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} \
		${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
