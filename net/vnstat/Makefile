# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	vnstat
PORTVERSION=	1.14
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://humdi.net/vnstat/ \
		http://mirror.mcx2.org/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Console-based network traffic monitor

LICENSE=	GPLv2

MAKE_ARGS=	CC="${CC}" CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=	bsdinstall

USE_RC_SUBR=	vnstat

USES=	gmake
USERS=	vnstat
GROUPS=	vnstat

BIN_BSD=	${PREFIX}/bin
SBIN_BSD=	${PREFIX}/sbin
MAN_BSD=	${MANDIRS}
ETC_BSD=	${PREFIX}/etc

PORTDOCS=	README INSTALL_BSD UPGRADE
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

# will compile with image output
OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=	GUI
GUI_DESC=	Build with graphics/gd dependency

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	libgd.so:graphics/gd
PLIST_SUB+=	GUI=""
.else
ALL_TARGET="vnstat"
PLIST_SUB+=	GUI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/src/cfg.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vnstat ${STAGEDIR}/${PREFIX}/bin/vnstat
	${INSTALL_PROGRAM} ${WRKSRC}/src/vnstatd ${STAGEDIR}/${PREFIX}/sbin/vnstatd
	${INSTALL_DATA} ${WRKSRC}/cfg/vnstat.conf ${STAGEDIR}/${PREFIX}/etc/vnstat.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.1 ${STAGEDIR}/${MANPREFIX}/man/man1/vnstat.1
	${INSTALL_MAN} ${WRKSRC}/man/vnstatd.1 ${STAGEDIR}/${MANPREFIX}/man/man1/vnstatd.1
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.conf.5 ${STAGEDIR}/${MANPREFIX}/man/man5/vnstat.conf.5
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/src/vnstati ${STAGEDIR}/${PREFIX}/bin/vnstati
	${INSTALL_MAN} ${WRKSRC}/man/vnstati.1 ${STAGEDIR}/${MANPREFIX}/man/man1/vnstati.1
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}/${DOCSDIR}
.endif

.include <bsd.port.mk>
