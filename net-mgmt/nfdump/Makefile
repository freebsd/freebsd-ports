PORTNAME=	nfdump
DISTVERSION=	1.7.8
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

LIB_DEPENDS=	liblz4.so:archivers/liblz4 libzstd.so:archivers/zstd

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/nfanon bin/nfcapd bin/nfdump \
		bin/nfexpire bin/nfreplay bin/sfcapd \
		bin/geolookup bin/updateGeoDB.sh \
		bin/torlookup bin/updateTorDB.sh \
		lib/libnfdump-${PORTVERSION}.so lib/libnfdump.so \
		lib/libnffile-${PORTVERSION}.so lib/libnffile.so \
		lib/libnfdump.a lib/libnffile.a \
		libdata/pkgconfig/nfdump.pc \
		share/man/man1/nfanon.1.gz share/man/man1/nfcapd.1.gz \
		share/man/man1/nfdump.1.gz share/man/man1/nfexpire.1.gz \
		share/man/man1/nfreplay.1.gz share/man/man1/sfcapd.1.gz \
		share/man/man1/geolookup.1.gz share/man/man1/torlookup.1.gz \
		etc/nfdump.conf.sample
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

OPTIONS_DEFINE=		DOCS FT2NFDUMP NFPCAPD NFPROFILE READPCAP
OPTIONS_DEFAULT=	NFPCAPD NFPROFILE READPCAP

FT2NFDUMP_DESC=		With Flow-tools to nfdump converter
NFPCAPD_DESC=		Build nfpcapd collector daemon also
NFPROFILE_DESC=		With nfprofile and nftrack (nfsen requires it)
READPCAP_DESC=		With pcap support

FT2NFDUMP_BUILD_DEPENDS=	flow-cat:net-mgmt/flow-tools
FT2NFDUMP_LIB_DEPENDS=	libft.so:net-mgmt/flow-tools
FT2NFDUMP_CONFIGURE_ON=	--enable-ftconv --with-ft=${LOCALBASE}
FT2NFDUMP_PLIST_FILES=	bin/ft2nfdump share/man/man1/ft2nfdump.1.gz
NFPCAPD_CONFIGURE_ENABLE=	nfpcapd
NFPCAPD_PLIST_FILES=	bin/nfpcapd share/man/man1/nfpcapd.1.gz
NFPROFILE_LIB_DEPENDS+=	librrd.so:databases/rrdtool
NFPROFILE_CONFIGURE_ON=	--enable-nfprofile --with-rrd=${LOCALBASE}
NFPROFILE_PLIST_FILES=	bin/nfprofile bin/nftrack share/man/man1/nfprofile.1.gz
READPCAP_LIB_DEPENDS=	libpcap.so:net/libpcap
READPCAP_CONFIGURE_ON=	--enable-readpcap --with-pcap=${LOCALBASE}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/nfdump.conf.dist ${STAGEDIR}${PREFIX}/etc/nfdump.conf.sample

.include <bsd.port.mk>
