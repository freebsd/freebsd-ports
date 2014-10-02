# Created by: gahr
# $FreeBSD$

PORTNAME=	tg
PORTVERSION=	1.0.5.1
CATEGORIES=	net-im

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Command-line interface for Telegram

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig

USE_GITHUB=	yes
GH_ACCOUNT=	vysheng
GH_TAGNAME=	1.0.5.1
GH_COMMIT=	77bbb4c

USES=		execinfo gmake lua:52 readline
GNU_CONFIGURE=	yes
CFLAGS+=	-g -O0

PLIST_FILES=	bin/telegram-cli \
		etc/tg-server.pub

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/telegram-cli ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
