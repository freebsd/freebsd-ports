PORTNAME=	nfdump
PORTVERSION=	1.6.20
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Command-line tools to collect and process NetFlow data
WWW=		https://github.com/phaag/nfdump

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-license.txt

USES=		autoreconf compiler:c11 cpe libtool pkgconfig
CPE_VENDOR=	nfdump_project
USE_CSTD=	gnu89
USE_GITHUB=	yes
GH_ACCOUNT=	phaag
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/nfanon bin/nfcapd bin/nfdump bin/nfexpire bin/nfreplay \
		lib/libnfdump-${PORTVERSION}.so \
		man/man1/nfanon.1.gz man/man1/nfcapd.1.gz man/man1/nfdump.1.gz \
		man/man1/nfexpire.1.gz man/man1/nfreplay.1.gz
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

#flow-tools support
OPTIONS_DEFINE=		DOCS FT2NFDUMP NFPROFILE FIXTIMEBUG READPCAP NFTRACK \
			SFLOW NFPCAPD NSEL INFLUXDB
OPTIONS_DEFAULT=	NFPROFILE

FIXTIMEBUG_DESC=	With fixing swap time bug of some v5
FT2NFDUMP_DESC=		With Flow-tools to nfdump converter
INFLUXDB_DESC=		Enable stats to InfluxDB
NFPCAPD_DESC=		Build nfpcapd collector daemon also
NFPROFILE_DESC=		With nfprofile (nfsen requires it)
NFTRACK_DESC=		With PortTracker support
NSEL_DESC=		Read and process ASA/NSEL/NEL event data
READPCAP_DESC=		With pcap support
SFLOW_DESC=		Build sflow collector daemon also

FIXTIMEBUG_CONFIGURE_ENABLE=	fixtimebug
FT2NFDUMP_BUILD_DEPENDS=		flow-cat:net-mgmt/flow-tools
FT2NFDUMP_LIB_DEPENDS=		libft.so:net-mgmt/flow-tools
FT2NFDUMP_CONFIGURE_ON=	--enable-ftconv --with-ftpath=${LOCALBASE}
FT2NFDUMP_PLIST_FILES=	bin/ft2nfdump man/man1/ft2nfdump.1.gz
INFLUXDB_LIB_DEPENDS=		libcurl.so:ftp/curl
INFLUXDB_CONFIGURE_ENABLE=	influxdb
NFPCAPD_CONFIGURE_ENABLE=	nfpcapd
NFPCAPD_PLIST_FILES=	bin/nfpcapd man/man1/nfpcapd.1.gz
NFPROFILE_CONFIGURE_ENABLE=	nfprofile
NFPROFILE_PLIST_FILES=	bin/nfprofile man/man1/nfprofile.1.gz
NFTRACK_CONFIGURE_ENABLE=	nftrack
NFTRACK_PLIST_FILES=	bin/nftrack
NSEL_CONFIGURE_ENABLE=	nsel
READPCAP_LIB_DEPENDS=		libpcap.so:net/libpcap
READPCAP_CONFIGURE_ENABLE=	readpcap
SFLOW_CONFIGURE_ENABLE=	sflow
SFLOW_PLIST_FILES=	bin/sfcapd man/man1/sfcapd.1.gz

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
CPPFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ${PORT_OPTIONS:MNFPROFILE} || ${PORT_OPTIONS:MNFTRACK}
CONFIGURE_ARGS+=	--with-rrdpath=${LOCALBASE}
BUILD_DEPENDS+=	rrdtool:databases/rrdtool
RUN_DEPENDS+=	rrdtool:databases/rrdtool
.endif

post-patch:
	${REINPLACE_CMD} 's|-ggdb||' ${WRKSRC}/bin/Makefile.am

do-install:
.for binary in nfanon nfcapd nfdump nfexpire nfreplay
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/${binary} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${binary}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
	${INSTALL_LIB} ${WRKSRC}/bin/.libs/libnfdump-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib

do-install-NFPROFILE-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/nfprofile ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/man/nfprofile.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-NFTRACK-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/nftrack ${STAGEDIR}${PREFIX}/bin

do-install-FT2NFDUMP-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/ft2nfdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/man/ft2nfdump.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-SFLOW-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/sfcapd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/man/sfcapd.1	${STAGEDIR}${PREFIX}/man/man1

do-install-NFPCAPD-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/nfpcapd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/man/nfpcapd.1	${STAGEDIR}${PREFIX}/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
