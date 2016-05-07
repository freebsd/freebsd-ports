# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	nfdump
PORTVERSION=	1.6.13
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Command-line tools to collect and process NetFlow data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-license.txt

GNU_CONFIGURE=	yes
USES=	libtool
USE_AUTOTOOLS=	autoconf:env autoheader:env
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

#flow-tools support
OPTIONS_DEFINE=		DOCS FT2NFDUMP NFPROFILE FIXTIMEBUG READPCAP NFTRACK \
			SFLOW NFDUMP15 NSEL
OPTIONS_DEFAULT=	NFPROFILE

FT2NFDUMP_DESC=		With Flow-tools to nfdump converter
NFPROFILE_DESC=		With nfprofile (nfsen requires it)
FIXTIMEBUG_DESC=	With fixing swap time bug of some v5
READPCAP_DESC=		With pcap support
NFTRACK_DESC=		With PortTracker support
SFLOW_DESC=		Build sflow collector daemon also
NFDUMP15_DESC=		Enable compatibility with version 1.5
NSEL_DESC=		Read and process ASA/NSEL/NEL event data

post-patch:
	@${REINPLACE_CMD} 's|-ggdb||' ${WRKSRC}/bin/Makefile.in

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

do-install:
.for binary in nfanon nfcapd nfdump nfexpire nfreplay
	${INSTALL_DATA} ${WRKSRC}/bin/${binary} ${STAGEDIR}${PREFIX}/bin
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${binary}
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/${binary}
.endfor

.if ${PORT_OPTIONS:MNFPROFILE}
	${INSTALL_DATA}	${WRKSRC}/bin/nfprofile	${STAGEDIR}${PREFIX}/bin
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/nfprofile
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/nfprofile
	${INSTALL_MAN}	${WRKSRC}/man/nfprofile.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MNFTRACK}
	${INSTALL_DATA}	${WRKSRC}/bin/nftrack	${STAGEDIR}${PREFIX}/bin
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/nftrack
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/nftrack
.endif

.if ${PORT_OPTIONS:MFT2NFDUMP}
	${INSTALL_DATA}	${WRKSRC}/bin/ft2nfdump	${STAGEDIR}${PREFIX}/bin
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/ft2nfdump
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/ft2nfdump
	${INSTALL_MAN}	${WRKSRC}/man/ft2nfdump.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MSFLOW}
	${INSTALL_DATA}	${WRKSRC}/bin/sfcapd	${STAGEDIR}${PREFIX}/bin
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/sfcapd
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/sfcapd
	${INSTALL_MAN}	${WRKSRC}/man/sfcapd.1	${STAGEDIR}${PREFIX}/man/man1
.endif

.for filename in nfanon nfdump nfcapd nfexpire nfreplay
	${INSTALL_MAN} ${WRKSRC}/man/${filename}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
