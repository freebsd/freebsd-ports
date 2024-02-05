PORTNAME=	vnstat
DISTVERSION=	2.12
CATEGORIES=	net
MASTER_SITES=	https://github.com/vergoh/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://humdi.net/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Console-based network traffic monitor
WWW=		https://humdi.net/vnstat/ \
		https://github.com/vergoh/vnstat

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase sqlite

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-exec install-man
USE_RC_SUBR=	vnstat

USERS=		vnstat
GROUPS=		vnstat

PORTDOCS=	README INSTALL_BSD UPGRADE
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

CONFIGURE_ARGS=	--disable-extra-paths

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=GUI
OPTIONS_SUB=	yes

GUI_DESC=	Build with graphics/gd dependency

GUI_LIB_DEPENDS=	libgd.so:graphics/gd
GUI_CONFIGURE_OFF=	--disable-image-output

post-install:
	${INSTALL_DATA} ${WRKSRC}/cfg/vnstat.conf ${STAGEDIR}${PREFIX}/etc/vnstat.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
