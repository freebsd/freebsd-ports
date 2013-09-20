# Created by: adam
# $FreeBSD$

PORTNAME=	pmf
PORTVERSION=	1.13.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.ntua.gr/pub/net/mud/lpmud/clients/pmf/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Padrone's Mud Frontend

WRKSRC=		${WRKDIR}/pmfdir/src

SYSSRC=		${WRKSRC}/../system_dir
DOCSRC=		${WRKSRC}/../doc
XMPSRC=		${WRKSRC}/../examples
SUB_FILES=	pmfrc.default

CFLAGS+=	-Wno-return-type

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmf ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${SYSSRC}/NEWS ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pmfrc.default ${DATADIR}
	@${MKDIR} ${DATADIR}/helpfiles
	${INSTALL_DATA} ${SYSSRC}/helpfiles/.pmfrc ${DATADIR}/helpfiles
	${INSTALL_DATA} ${SYSSRC}/helpfiles/* ${DATADIR}/helpfiles
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${XMPSRC}/.pmfrc ${EXAMPLESDIR}/dot.pmfrc
	${INSTALL_DATA} ${XMPSRC}/* ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCSRC}/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
