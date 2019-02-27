# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	nfdump
PORTVERSION=	1.6.17
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Command-line tools to collect and process NetFlow data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-license.txt

USES=		autoreconf libtool pkgconfig
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	phaag

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

#flow-tools support
OPTIONS_DEFINE=		DOCS FT2NFDUMP NFPROFILE FIXTIMEBUG READPCAP NFTRACK \
			SFLOW NFDUMP15 NSEL INFLUXDB
OPTIONS_DEFAULT=	NFPROFILE

FT2NFDUMP_DESC=		With Flow-tools to nfdump converter
NFPROFILE_DESC=		With nfprofile (nfsen requires it)
FIXTIMEBUG_DESC=	With fixing swap time bug of some v5
READPCAP_DESC=		With pcap support
NFTRACK_DESC=		With PortTracker support
SFLOW_DESC=		Build sflow collector daemon also
NFDUMP15_DESC=		Enable compatibility with version 1.5
NSEL_DESC=		Read and process ASA/NSEL/NEL event data
INFLUXDB_DESC=		Enable stats to InfluxDB

post-patch:
	${REINPLACE_CMD} 's|-ggdb||' ${WRKSRC}/bin/Makefile.am
	${REINPLACE_CMD} "s|1.6.15|${PORTVERSION}|" ${WRKSRC}/bin/Makefile.am

.include <bsd.port.options.mk>

#for compatibility
#
.if ${PORT_OPTIONS:MNFDUMP15}
CONFIGURE_ARGS+=	--enable-compat15
.else
CONFIGURE_ARGS+=	--disable-compat15
.endif

.if ${PORT_OPTIONS:MNSEL}
CONFIGURE_ARGS+=	--enable-nsel
.else
CONFIGURE_ARGS+=	--disable-nsel
.endif

PLIST_FILES=	bin/nfanon bin/nfcapd bin/nfdump bin/nfexpire bin/nfreplay \
		lib/libnfdump-${PORTVERSION}.so \
		man/man1/nfanon.1.gz man/man1/nfcapd.1.gz man/man1/nfdump.1.gz \
		man/man1/nfexpire.1.gz man/man1/nfreplay.1.gz
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

.if ${PORT_OPTIONS:MFIXTIMEBUG}
CONFIGURE_ARGS+=	--enable-fixtimebug
.else
CONFIGURE_ARGS+=	--disable-fixtimebug
.endif

.if ${PORT_OPTIONS:MNFPROFILE}
CONFIGURE_ARGS+=	--enable-nfprofile
PLIST_FILES+=	bin/nfprofile man/man1/nfprofile.1.gz
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
BUILD_DEPENDS+=	rrdtool:databases/rrdtool
RUN_DEPENDS+=	rrdtool:databases/rrdtool
.endif

#flow-tools support
.if ${PORT_OPTIONS:MFT2NFDUMP}
BUILD_DEPENDS+=		flow-cat:net-mgmt/flow-tools
CONFIGURE_ARGS+=	--enable-ftconv --with-ftpath=${LOCALBASE}
PLIST_FILES+=	bin/ft2nfdump man/man1/ft2nfdump.1.gz
.endif

.if ${PORT_OPTIONS:MREADPCAP}
CONFIGURE_ARGS+=	--enable-readpcap
LIB_DEPENDS+=		libpcap.so:net/libpcap
.else
CONFIGURE_ARGS+=	--disable-readpcap
.endif

#sflow capture support
.if ${PORT_OPTIONS:MSFLOW}
CONFIGURE_ARGS+=	--enable-sflow
PLIST_FILES+=	bin/sfcapd man/man1/sfcapd.1.gz
.else
CONFIGURE_ARGS+=	--disable-sflow
.endif

#influxdb support
.if ${PORT_OPTIONS:MINFLUXDB}
CONFIGURE_ARGS+=	--enable-influxdb
LIB_DEPENDS+=		libcurl.so:ftp/curl
.else
CONFIGURE_ARGS+=	--disable-influxdb
.endif

do-install:
.for binary in nfanon nfcapd nfdump nfexpire nfreplay
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/${binary} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_LIB} ${WRKSRC}/bin/.libs/libnfdump-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib

.if ${PORT_OPTIONS:MNFPROFILE}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/nfprofile ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/man/nfprofile.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MNFTRACK}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/nftrack ${STAGEDIR}${PREFIX}/bin
.endif

.if ${PORT_OPTIONS:MFT2NFDUMP}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/ft2nfdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/man/ft2nfdump.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MSFLOW}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/sfcapd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/man/sfcapd.1	${STAGEDIR}${PREFIX}/man/man1
.endif

.for filename in nfanon nfdump nfcapd nfexpire nfreplay
	${INSTALL_MAN} ${WRKSRC}/man/${filename}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
