PORTNAME=	nfdump
PORTVERSION=	1.7.4
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Command-line tools to collect and process NetFlow, sFlow and IPFIX data
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
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/nfanon bin/nfcapd bin/nfdump bin/nfexpire bin/nfreplay \
		lib/libnfdump-${PORTVERSION}.so lib/libnfdump.so \
		lib/libnfdump.a \
		share/man/man1/nfanon.1.gz share/man/man1/nfcapd.1.gz \
		share/man/man1/nfdump.1.gz share/man/man1/nfexpire.1.gz \
		share/man/man1/nfreplay.1.gz \
		etc/nfdump.conf.sample
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

#flow-tools support
OPTIONS_DEFINE=		DOCS FT2NFDUMP NFPROFILE FIXTIMEBUG READPCAP NFTRACK \
			SFLOW NFPCAPD NSEL INFLUXDB GEODB
OPTIONS_DEFAULT=	NFPROFILE NFPCAPD READPCAP NFTRACK NSEL SFLOW

FIXTIMEBUG_DESC=	With fixing swap time bug of some v5
FT2NFDUMP_DESC=		With Flow-tools to nfdump converter
INFLUXDB_DESC=		Enable stats to InfluxDB
NFPCAPD_DESC=		Build nfpcapd collector daemon also
NFPROFILE_DESC=		With nfprofile (nfsen requires it)
NFTRACK_DESC=		With PortTracker support
NSEL_DESC=		Read and process ASA/NSEL/NEL event data
READPCAP_DESC=		With pcap support
SFLOW_DESC=		Build sflow collector daemon also
GEODB_DESC=		Build geolookup for MaxMind GeoDB

FIXTIMEBUG_CONFIGURE_ENABLE=	fixtimebug
FT2NFDUMP_BUILD_DEPENDS=		flow-cat:net-mgmt/flow-tools
FT2NFDUMP_LIB_DEPENDS=		libft.so:net-mgmt/flow-tools
FT2NFDUMP_CONFIGURE_ON=	--enable-ftconv --with-ftpath=${LOCALBASE}
FT2NFDUMP_PLIST_FILES=	bin/ft2nfdump share/man/man1/ft2nfdump.1.gz
INFLUXDB_LIB_DEPENDS=		libcurl.so:ftp/curl
INFLUXDB_CONFIGURE_ENABLE=	influxdb
NFPCAPD_CONFIGURE_ENABLE=	nfpcapd
NFPCAPD_PLIST_FILES=	bin/nfpcapd share/man/man1/nfpcapd.1.gz
NFPROFILE_CONFIGURE_ENABLE=	nfprofile
NFPROFILE_PLIST_FILES=	bin/nfprofile share/man/man1/nfprofile.1.gz
NFTRACK_CONFIGURE_ENABLE=	nftrack
NFTRACK_PLIST_FILES=	bin/nftrack
NSEL_CONFIGURE_ENABLE=	nsel
READPCAP_CONFIGURE_ENABLE=	readpcap
SFLOW_CONFIGURE_ENABLE=	sflow
SFLOW_PLIST_FILES=	bin/sfcapd share/man/man1/sfcapd.1.gz
GEODB_PLIST_FILES=	bin/geolookup bin/updateGeoDB.sh share/man/man1/geolookup.1.gz
GEODB_CONFIGURE_ENABLE=	maxmind

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CPPFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ${PORT_OPTIONS:MNFPROFILE} || ${PORT_OPTIONS:MNFTRACK}
CONFIGURE_ARGS+=	--with-rrdpath=${LOCALBASE}
BUILD_DEPENDS+=	rrdtool:databases/rrdtool
RUN_DEPENDS+=	rrdtool:databases/rrdtool
.endif

post-patch:
	${REINPLACE_CMD} 's|-ggdb||' ${WRKSRC}/src/lib/Makefile.am
	${REINPLACE_CMD} 's|-ggdb||' ${WRKSRC}/src/nfcapd/Makefile.am
	${REINPLACE_CMD} 's|-ggdb||' ${WRKSRC}/src/test/Makefile.am

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/nfdump.conf.dist ${STAGEDIR}${PREFIX}/etc/nfdump.conf.sample

.include <bsd.port.post.mk>
