PORTNAME=	vnstat
PORTVERSION=	2.12
CATEGORIES=	net
MASTER_SITES=	https://github.com/vergoh/vnstat/releases/download/v${PORTVERSION}/ \
		https://humdi.net/vnstat/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Console-based network traffic monitor
WWW=		https://humdi.net/vnstat/ \
		https://github.com/vergoh/vnstat

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase sqlite

CONFIGURE_ARGS=	--disable-extra-paths
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-exec install-man
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

GUI_CONFIGURE_OFF=	--disable-image-output
GUI_LIB_DEPENDS=	libgd.so:graphics/gd

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/cfg/vnstat.conf ${STAGEDIR}${PREFIX}/etc/vnstat.conf.sample

.include <bsd.port.mk>
