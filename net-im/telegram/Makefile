# Created by: gahr
# $FreeBSD$

PORTNAME=	telegram
PORTVERSION=	1.0.5.1
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line interface for Telegram

LICENSE=	GPLv2

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig \
    		libevent.so:${PORTSDIR}/devel/libevent2

USE_GITHUB=	yes
GH_ACCOUNT=	vysheng
GH_PROJECT=	tg

USES=		execinfo gmake lua:52 ncurses pkgconfig readline
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/telegram-cli \
		etc/tg-server.pub

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/telegram-cli ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
