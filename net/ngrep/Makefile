# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	ngrep
PORTVERSION=	1.45
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	logan@elandsys.com
COMMENT=	Network grep

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake tar:bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-pcap-restart

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		CAPSICUM DOCS IPV6 PCRE PORTS_PCAP
OPTIONS_DEFAULT=	CAPSICUM IPV6 PCRE

PCRE_DESC=		Use PCRE instead of GNU regex
PORTS_PCAP_DESC=	Use ports PCAP instead of system PCAP
CAPSICUM_DESC=		Build with capsicum if kernel supports it

PLIST_FILES=	bin/ngrep man/man8/ngrep.8.gz

PORTDOCS=	CHANGES.txt CREDITS.txt INSTALL.txt LICENSE.txt \
		README.txt REGEX.txt

CAPSICUM_CONFIGURE_ON=	--enable-capsicum

IPV6_CONFIGURE_ENABLE=	ipv6
PCRE_CONFIGURE_ENABLE=	pcre

PORTS_PCAP_CONFIGURE_ON=	--with-pcap-includes=${LOCALBASE}/include
PORTS_PCAP_CONFIGURE_OFF=	--with-pcap-includes=/usr/include
PORTS_PCAP_BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:net/libpcap

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MPORTS_PCAP}
	@${REINPLACE_CMD} -e "s|-lpcap|${LOCALBASE}/lib/libpcap.a|g" \
		${WRKSRC}/Makefile.in ${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	@if [ -f ${WRKSRC}/${file} ]; then \
		${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}; \
	else \
		${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}; \
	fi
.endfor
.endif

.include <bsd.port.mk>
