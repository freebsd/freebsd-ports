PORTNAME=	arpwatch
PORTVERSION=	3.3
CATEGORIES=	net-mgmt
MASTER_SITES=	https://ee.lbl.gov/downloads/arpwatch/ \
		LOCAL/leres/arpwatch

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Monitor arp & rarp requests

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/pcap.h:net/libpcap
RUN_DEPENDS=	${LOCALBASE}/include/pcap.h:net/libpcap

USES=		python:run

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sendmail=/usr/sbin/sendmail

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG ZEROPAD
OPTIONS_DEFAULT=ZEROPAD
OPTIONS_SUB=	yes

ZEROPAD_DESC=	zero pad displayed ethernet addresses by default

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--disable-optimization
.endif

.if ${PORT_OPTIONS:MZEROPAD}
CONFIGURE_ARGS+=	--enable-zeropad
.endif

.ifdef ARPDIR
MAKE_ARGS=	ARPDIR=${ARPDIR}
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/arpwatch
.for F in d.awk duplicates.awk euppertolower.awk e.awk p.awk
	${INSTALL_DATA} ${WRKSRC}/${F} ${STAGEDIR}${PREFIX}/arpwatch
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/arp2ethers ${STAGEDIR}${PREFIX}/arpwatch
	${INSTALL_SCRIPT} ${WRKSRC}/massagevendor.py \
	    ${STAGEDIR}${PREFIX}/arpwatch/massagevendor
	${INSTALL_SCRIPT} ${WRKSRC}/update-ethercodes.sh \
	    ${STAGEDIR}${PREFIX}/arpwatch/update-ethercodes

post-configure:
	${REINPLACE_CMD} -e "/^LIBS *=/s,-lpcap,${LOCALBASE}/lib/libpcap.so.1," \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
