# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	vnstat
PORTVERSION=	1.11
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://humdi.net/vnstat/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A console-based network traffic monitor

MAKE_ARGS=	CC="${CC}" CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=	bsdinstall

USE_RC_SUBR=	vnstat

USERS=	vnstat
GROUPS=	vnstat

MAN1=	vnstat.1 vnstatd.1
MAN5=	vnstat.conf.5
MANCOMPRESSED=	yes
PORTDOCS=	README INSTALL_BSD UPGRADE vnstat-cron
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

# will compile with image output
OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=	GUI
GUI_DESC=	Build with graphics/gd dependency

.include <bsd.port.options.mk>

PLIST_FILES=	bin/vnstat \
		sbin/vnstatd \
		%%GUI%%bin/vnstati \
		etc/vnstat.conf.sample

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
PLIST_SUB+=	GUI=""
MAN1+=	vnstati.1
.else
ALL_TARGET="vnstat"
PLIST_SUB+=	GUI="@comment "
.endif

post-extract:
	@cd ${WRKSRC} && ${CP} examples/vnstat.cron vnstat-cron
	@cd ${WRKSRC} && ${CP} cfg/vnstat.conf cfg/vnstat.conf.sample
	@${REINPLACE_CMD} -e 's|/usr/bin|/usr/local/bin|g' \
		-e 's|ls /var/lib|ls -l /var/db|g' ${WRKSRC}/vnstat-cron

post-patch:
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)|${PREFIX}|g' \
		-e 's|cfg/vnstat.conf|cfg/vnstat.conf.sample|g' \
		-e 's|etc/vnstat.conf|etc/vnstat.conf.sample|g' \
		-e 's|install -D|install|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/src/cfg.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
