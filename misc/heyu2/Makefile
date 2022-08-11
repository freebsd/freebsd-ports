PORTNAME=	heyu2
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.heyu.org/download/
DISTNAME=	heyu-${PORTVERSION}

MAINTAINER=	mstowe@chicago.us.mensa.org
COMMENT=	Control a CM11A interface from the command line

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: newsb
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: newsb

CONFLICTS=	heyu

ALL_TARGET=	all

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	freebsd

OPTIONS_DEFINE=	CM17A EXTENDED RFXSENS RFXMETER DMX OREGON EXAMPLES
CM17A_DESC=	X10 CM17A "Firecracker" Support
EXTENDED_DESC=	Extended Type 0 (Shutter/Shade) Support
RFXSENS_DESC=	RFXSensors (RF) Support
RFXMETER_DESC=	RFXMeter (RF) Support
DMX_DESC=	Digimax Thermostat Support
OREGON_DESC=	Oregon Support

OPTIONS_DEFAULT=	CM17A EXTENDED RFXSENS RFXMETER DMX OREGON

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MCM17A}
CONFIGURE_ARGS+=	nocm17a
.endif

.if ! ${PORT_OPTIONS:MEXTENDED}
CONFIGURE_ARGS+=	noext0
.endif

.if ! ${PORT_OPTIONS:MRFXSENS}
CONFIGURE_ARGS+=	norfxs
.endif

.if ! ${PORT_OPTIONS:MRFXMETER}
CONFIGURE_ARGS+=	norfxm
.endif

.if ! ${PORT_OPTIONS:MDMX}
CONFIGURE_ARGS+=	nodmx
.endif

.if ! ${PORT_OPTIONS:MOREGON}
CONFIGURE_ARGS+=	noore
.endif

post-patch:
	@${REINPLACE_CMD} -E 's|/usr/local|${PREFIX}|g; \
			     s,(CC) =,\1 ?=,g; \
			     s,(CFLAGS) =,\1 +=,g' \
		${WRKSRC}/Configure
	@${REINPLACE_CMD} -e 's|<.*termio[s]*.h|<sys/ttycom.h|g' \
		${WRKSRC}/cm17a.c \
		${WRKSRC}/xsync.c \
		${WRKSRC}/xwrite.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heyu ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/heyu.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/x10aux.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10config.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10cm17a.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10digimax.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10oregon.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10sched.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10scripts.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10rfxmeters.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10rfxsensors.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10config.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/x10.sched.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
