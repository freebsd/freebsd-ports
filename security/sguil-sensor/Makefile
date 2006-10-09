# New ports collection makefile for:	sguil-sensor
# Date created:				23 Mar 2006
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	sguil-sensor
PORTVERSION=	0.6.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sguil

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Squil is a network security management program

RUN_DEPENDS=	snort:${PORTSDIR}/security/snort \
		barnyard:${PORTSDIR}/security/barnyard-sguil6 \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:${PORTSDIR}/lang/tclX

OPTIONS=	SANCP "Include sancp support" off \
		TLS "Include openssl support" off

NO_BUILD=	yes
USE_RC_SUBR=	sensor_agent.sh
TCLSH_CMD?=	tclsh8.4
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
SUB_LIST=	SGUILDIR=${SGUILDIR}
SUB_FILES=	pkg-message sensor_agent.sh
PLIST_SUB=	SGUILDIR=${SGUILDIR}
SGUILDIR?=	sguil-sensor

PORTDOCS=	CHANGES FAQ INSTALL INSTALL.openbsd LICENSE.QPL \
		OPENSSL.README TODO UPGRADE USAGE sguildb.dia

.include <bsd.port.pre.mk>

WITH_PCRE=	true

.if defined(WITH_SANCP)
RUN_DEPENDS+=	sancp:${PORTSDIR}/security/sancp
PLIST_SUB+=	USESANCP=
.else
PLIST_SUB+=	USESANCP="@comment "
.endif

.if defined(WITH_TLS)
LIB_DEPENDS+=	tls:${PORTSDIR}/devel/tcltls
.endif

post-patch:
.for f in sensor_agent.tcl
	@${REINPLACE_CMD} -e 's:exec tclsh:exec ${PREFIX}/bin/${TCLSH_CMD}:g' \
		${WRKSRC}/sensor/${f}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/bin/${SGUILDIR}
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/sensor/sensor_agent.tcl \
		${PREFIX}/bin/${SGUILDIR}/sensor_agent.tcl
.for f in log_packets.sh
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/sensor/${f} \
		${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.for f in sensor_agent.conf
	${INSTALL_DATA} ${WRKSRC}/sensor/${f} \
		${PREFIX}/etc/${f}-sample
.endfor
.for f in log_packets.conf
	${INSTALL_DATA} ${FILESDIR}/${f} \
		${PREFIX}/etc/${f}-sample
.endfor
.if defined(WITH_SANCP)
.for f in sancp.conf
	${INSTALL_DATA} ${WRKSRC}/sensor/sancp/${f} \
		${PREFIX}/etc/${f}-sample
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} \
		${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
