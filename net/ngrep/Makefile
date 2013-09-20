# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	ngrep
PORTVERSION=	1.45
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	edwin@mavetju.org
COMMENT=	Network grep

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	ngrep
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-pcap-restart
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PCRE PORTS_PCAP IPV6 DOCS
OPTIONS_DEFAULT=	PCRE
PCRE_DESC=		Use PCRE instead of GNU regex
PORTS_PCAP_DESC=	Use ports PCAP instead of system PCAP

MAN8=		ngrep.8
PLIST_FILES=	bin/ngrep

PORTDOCS=	CHANGES.txt CREDITS.txt INSTALL.txt LICENSE.txt \
		README.txt REGEX.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=	--enable-pcre
.endif

.if ${PORT_OPTIONS:MPORTS_PCAP}
CONFIGURE_ARGS+=	--with-pcap-includes=${LOCALBASE}/include
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.else
CONFIGURE_ARGS+=	--with-pcap-includes=/usr/include
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
.if ${PORT_OPTIONS:MPORTS_PCAP}
	@${REINPLACE_CMD} -e "s|-lpcap|${LOCALBASE}/lib/libpcap.a|g" \
		${WRKSRC}/Makefile.in ${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@if [ -f ${WRKSRC}/${file} ]; then \
		${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}; \
	else \
		${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}; \
	fi
.endfor
.endif

.include <bsd.port.mk>
