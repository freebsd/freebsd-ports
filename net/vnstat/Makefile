# New ports collection makefile for:	vnstat
# Date created:		February 17, 2008
# Whom:		Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	vnstat
PORTVERSION=	1.9
CATEGORIES=	net
MASTER_SITES=	http://humdi.net/vnstat/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A console-based network traffic monitor

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

MAKE_ARGS=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=	bsdinstall

MAN1=	vnstat.1 vnstatd.1 vnstati.1
MAN5=	vnstat.conf.5
MANCOMPRESSED=	yes
PORTDOCS=	README INSTALL_BSD UPGRADE vnstat-cron
SUB_FILES=	pkg-message

PLIST_FILES=	bin/vnstat \
		sbin/vnstatd \
		bin/vnstati \
		etc/vnstat.conf.sample

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
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
