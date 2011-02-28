# New ports collection makefile for:	nfdump
# Date created:				2004-09-29
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfdump
PORTVERSION=	1.6.3p1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Command-line tools to collect and process NetFlow data

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/BSD-license.txt

#flow-tools support
OPTIONS=	FT2NFDUMP	"With Flow-tools to nfdump converter" off \
		NFPROFILE	"With nfprofile  (nfsen requires it)" on \
		FIXTIMEBUG      "With fixing swap time bug of some v5" off \
		READPCAP        "With pcap support" off \
		NFTRACK         "With PortTracker support" off \
		SFLOW		"Build sflow collector daemon also" off

.include <bsd.port.pre.mk>

#for compatibility
#
.ifndef(WITHOUT_NFDUMP15_SUPPORT)
CONFIGURE_ARGS=		--enable-compat15
.endif

PLIST_FILES=	bin/nfanon bin/nfcapd bin/nfdump bin/nfexpire bin/nfreplay
MAN1=		nfanon.1 nfcapd.1 nfdump.1 nfexpire.1 nfreplay.1
MAN1+=		ft2nfdump.1 nfprofile.1 sfcapd.1
PORTDOCS=	AUTHORS ChangeLog INSTALL README

.if defined(WITH_FIXTIMEBUG)
CONFIGURE_ARGS+=	--enable-fixtimebug
.endif

.if defined(WITH_NFPROFILE)
CONFIGURE_ARGS+=	--enable-nfprofile
PLIST_FILES+=	bin/nfprofile
.endif

.if defined(WITH_NFTRACK)
CONFIGURE_ARGS+=	--enable-nftrack
PLIST_FILES+=	bin/nftrack
.endif

.if defined(WITH_NFPROFILE) || defined(WITH_NFTRACK)
CONFIGURE_ARGS+=	--with-rrdpath=${LOCALBASE}
BUILD_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
.endif

#flow-tools support
.if defined(WITH_FT2NFDUMP)
BUILD_DEPENDS+=		flow-cat:${PORTSDIR}/net-mgmt/flow-tools
CONFIGURE_ARGS+=	--enable-ftconv --with-ftpath=${LOCALBASE}
PLIST_FILES+=	bin/ft2nfdump
.endif

.if defined (WITH_READPCAP)
CONFIGURE_ARGS+=	--enable-readpcap
.endif

#sflow capture support
.if defined(WITH_SFLOW)
CONFIGURE_ARGS+=	--enable-sflow
PLIST_FILES+=	bin/sfcapd
#MAN1+=		sfcapd.1
.endif

post-configure:
	@${REINPLACE_CMD} -E -e 's/sfcapd\.1/sfcapd\.1 nfanon\.1/' ${WRKSRC}/man/Makefile

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
