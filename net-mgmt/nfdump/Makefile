# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	nfdump
PORTVERSION=	1.6.8
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Command-line tools to collect and process NetFlow data

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/BSD-license.txt

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_CSTD=	gnu89

#flow-tools support
OPTIONS_DEFINE=		FT2NFDUMP NFPROFILE FIXTIMEBUG READPCAP NFTRACK \
			SFLOW NFDUMP15
OPTIONS_DEFAULT=	NFPROFILE

FT2NFDUMP_DESC=		With Flow-tools to nfdump converter
NFPROFILE_DESC=		With nfprofile (nfsen requires it)
FIXTIMEBUG_DESC=	With fixing swap time bug of some v5
READPCAP_DESC=		With pcap support
NFTRACK_DESC=		With PortTracker support
SFLOW_DESC=		Build sflow collector daemon also
NFDUMP15_DESC=		Enable compatbility with version 1.5

.include <bsd.port.options.mk>

#for compatibility
#
.if ${PORT_OPTIONS:MNFDUMP15}
CONFIGURE_ARGS+=	--enable-compat15
.else
CONFIGURE_ARGS+=	--disable-compat15
.endif

PLIST_FILES=	bin/nfanon bin/nfcapd bin/nfdump bin/nfexpire bin/nfreplay \
		bin/nftrack
MAN1=		nfanon.1 nfcapd.1 nfdump.1 nfexpire.1 nfreplay.1
MAN1+=		ft2nfdump.1 nfprofile.1 sfcapd.1
PORTDOCS=	AUTHORS ChangeLog INSTALL README

.if ${PORT_OPTIONS:MFIXTIMEBUG}
CONFIGURE_ARGS+=	--enable-fixtimebug
.else
CONFIGURE_ARGS+=	--disable-fixtimebug
.endif

.if ${PORT_OPTIONS:MNFPROFILE}
CONFIGURE_ARGS+=	--enable-nfprofile
PLIST_FILES+=	bin/nfprofile
.else
CONFIGURE_ARGS+=	--disable-nfprofile
.endif

.if ${PORT_OPTIONS:MNFTRACK}
CONFIGURE_ARGS+=	--enable-nftrack
PLIST_FILES+=	bin/nftrack
.else
CONFIGURE_ARGS+=	--disable-nftrack
.endif

.if ${PORT_OPTIONS:MNFPROFILE} || ${PORT_OPTIONS:MNFTRACK}
CONFIGURE_ARGS+=	--with-rrdpath=${LOCALBASE}
BUILD_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
.endif

#flow-tools support
.if ${PORT_OPTIONS:MFT2NFDUMP}
BUILD_DEPENDS+=		flow-cat:${PORTSDIR}/net-mgmt/flow-tools
CONFIGURE_ARGS+=	--enable-ftconv --with-ftpath=${LOCALBASE}
PLIST_FILES+=	bin/ft2nfdump
.endif

.if ${PORT_OPTIONS:MREADPCAP}
CONFIGURE_ARGS+=	--enable-readpcap
.else
CONFIGURE_ARGS+=	--disable-readpcap
.endif

#sflow capture support
.if ${PORT_OPTIONS:MSFLOW}
CONFIGURE_ARGS+=	--enable-sflow
PLIST_FILES+=	bin/sfcapd
#MAN1+=		sfcapd.1
.else
CONFIGURE_ARGS+=	--disable-sflow
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
