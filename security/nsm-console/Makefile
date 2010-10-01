# New ports collection makefile for:	nsm-console
# Date created:		2008-01-15
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	nsm-console
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://writequit.org/projects/nsm-console/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A framework for performing analysis on packet capture files

BROKEN=		does not fetch

USE_RUBY=	yes
NO_BUILD=	yes
RUBY_NO_BUILD_DEPENDS=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}
OPTIONS=	TSHARK		"Install tshark" on \
			WIRESHARK	"Install wireshark" off \
			TCPDSTAT	"Install tcpdstat" on \
			NGREP		"Install ngrep" on \
			TCPFLOW 	"Install tcpflow" on \
			SNORT		"Install snort" on \
			TCPXTRACT	"Install tcpxtract" on \
			P0F			"Install p0f" on \
			PADS		"Install pads" on \
			FL0P		"Install fl0p" on \
			CHAOSREADER	"Install chaosreader" on \
			ARGUS		"Install argus" on \
			TCPICK		"Install tcpick" on \
			TCPTRACE	"Install tcptrace" on \
			FOREMOST	"Install foremost" on \
			CHAOSREADER	"Install chaosreader" on
NSM_DOC=	CHANGELOG TODO

.include <bsd.port.pre.mk>

.if defined(WITH_TSHARK)
RUN_DEPEND+=	${LOCALBASE}/bin/tshark:${PORTSDIR}/net/tshark
.endif
.if defined(WITH_WIRESHARK)
.if defined(WITH_TSHARK)
IGNORE=	you cannot enable both WIRESHARK and TSHARK
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/wireshark:${PORTSDIR}/net/wireshark
.endif
.endif
.if defined(WITH_TCPDSTAT)
RUN_DEPENDS+=	${LOCALBASE}/bin/tcpdstat:${PORTSDIR}/net/tcpdstat
.endif
.if defined(WITH_NGREP)
RUN_DEPENDS+=	${LOCALBASE}/bin/ngrep:${PORTSDIR}/net/ngrep
.endif
.if defined(WITH_TCPFLOW)
RUN_DEPENDS+=	${LOCALBASE}/bin/tcpflow:${PORTSDIR}/net/tcpflow
.endif
.if defined(WITH_SNORT)
RUN_DEPENDS+=	${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort
.endif
.if defined(WITH_TCPXTRACT)
RUN_DEPENDS+=	${LOCALBASE}/bin/tcpxtract:${PORTSDIR}/net/tcpxtract
.endif
.if defined(WITH_P0F)
RUN_DEPENDS+=	${LOCALBASE}/bin/p0f:${PORTSDIR}/net-mgmt/p0f
.endif
.if defined(WITH_PADS)
RUN_DEPENDS+=	${LOCALBASE}/bin/pads:${PORTSDIR}/net-mgmt/pads
.endif
.if defined(WITH_FL0P)
RUN_DEPENDS+=	${LOCALBASE}/bin/fl0p:${PORTSDIR}/security/fl0p
.endif
.if defined(WITH_CHAOSREADER)
RUN_DEPENDS+=	${LOCALBASE}/bin/chaosreader:${PORTSDIR}/security/chaosreader
.endif
.if defined(WITH_ARGUS)
RUN_DEPENDS+=	${LOCALBASE}/bin/ra:${PORTSDIR}/net-mgmt/argus3-clients \
	${LOCALBASE}/sbin/argus:${PORTSDIR}/net-mgmt/argus3
.endif
.if defined(WITH_TCPICK)
RUN_DEPENDS+=	${LOCALBASE}/bin/tcpick:${PORTSDIR}/net/tcpick
.endif
.if defined(WITH_TCPTRACE)
RUN_DEPENDS+=	${LOCALBASE}/bin/tcptrace:${PORTSDIR}/net/tcptrace
.endif
.if defined(WITH_FOREMOST)
RUN_DEPENDS+=	${LOCALBASE}/bin/foremost:${PORTSDIR}/sysutils/foremost
.endif
.if defined(WITH_CHAOSREADER)
RUN_DEPENDS+=	${LOCALBASE}/bin/chaosreader:${PORTSDIR}/security/chaosreader
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/nsm

do-install:
	@${MKDIR} ${RUBY_SITELIBDIR}/${PORTNAME}
	@( cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${RUBY_SITELIBDIR}/${PORTNAME} )
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.for D in modules
	@${MKDIR} ${DATADIR}/${D}
	@( cd ${WRKSRC}/${D} && ${COPYTREE_SHARE} . ${DATADIR}/${D} )
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/nsm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for F in ${NSM_DOC}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
