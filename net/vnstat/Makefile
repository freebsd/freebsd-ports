# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	vnstat
PORTVERSION=	2.6
CATEGORIES=	net
MASTER_SITES=	https://humdi.net/vnstat/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Console-based network traffic monitor

LICENSE=	GPLv2

USES=		sqlite

GNU_CONFIGURE=	yes
USE_RC_SUBR=	vnstat

USERS=		vnstat
GROUPS=		vnstat

PORTDOCS=	README INSTALL_BSD UPGRADE
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=GUI
OPTIONS_SUB=	yes
GUI_DESC=	Build with graphics/gd dependency

GUI_LIB_DEPENDS=	libgd.so:graphics/gd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnstat ${STAGEDIR}${PREFIX}/bin/vnstat
	${INSTALL_DATA} ${WRKSRC}/cfg/vnstat.conf ${STAGEDIR}${PREFIX}/etc/vnstat.conf.sample
	${INSTALL_PROGRAM} ${WRKSRC}/vnstatd ${STAGEDIR}${PREFIX}/sbin/vnstatd
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.1 ${STAGEDIR}${PREFIX}/share/man/man1/vnstat.1
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/vnstat.conf.5
	${INSTALL_MAN} ${WRKSRC}/man/vnstatd.8 ${STAGEDIR}${PREFIX}/share/man/man8/vnstatd.8

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/vnstati ${STAGEDIR}${PREFIX}/bin/vnstati
	${INSTALL_MAN} ${WRKSRC}/man/vnstati.1 ${STAGEDIR}${PREFIX}/share/man/man1/vnstati.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
