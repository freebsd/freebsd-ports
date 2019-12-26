# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arpwatch
PORTVERSION=	3.0
PORTREVISION=	3
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

SUB_FILES=      pkg-message

OPTIONS_DEFINE=	DEBUG ETHERCODES ZEROPAD
OPTIONS_DEFAULT=ETHERCODES ZEROPAD
OPTIONS_SUB=	yes

ETHERCODES_DESC=install ethercodes.dat
ZEROPAD_DESC=	zero pad displayed ethernet addresses by default

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=        --disable-optimization
.endif

.if ${PORT_OPTIONS:MZEROPAD}
CONFIGURE_ARGS+=        --enable-zeropad
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
.if ${PORT_OPTIONS:METHERCODES}
	${INSTALL_DATA} ${WRKSRC}/ethercodes.dat ${STAGEDIR}${PREFIX}/arpwatch
.endif

post-configure:
	${REINPLACE_CMD} -e "/^LIBS *=/s,-lpcap,${LOCALBASE}/lib/libpcap.so.1," \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
