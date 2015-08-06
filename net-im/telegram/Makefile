# Created by: gahr
# $FreeBSD$

PORTNAME=	telegram
PORTVERSION=	1.3.1
CATEGORIES=	net-im
MASTER_SITES=	http://github.com/vysheng/tg/archive/:source1 \
		http://github.com/vysheng/tgl/archive/:source2 \
		http://github.com/vysheng/tl-parser/archive/:source3
DISTFILES=	1.3.1.tar.gz:source1 2.0.1.tar.gz:source2 master.zip:source3

MAINTAINER=	cpm@fbsd.es
COMMENT=	Command-line interface for Telegram

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig \
    		libevent.so:${PORTSDIR}/devel/libevent2 \
		libjansson.so:${PORTSDIR}/devel/jansson

USES=		execinfo gmake lua:52 ncurses pkgconfig readline
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/tg-1.3.1

PLIST_FILES=	bin/telegram-cli \
		etc/telegram-cli/server.pub
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
USE_GCC=	4.8+
.endif

post-extract:
	@${MV} ${WRKDIR}/tgl-2.0.1/* ${WRKSRC}/tgl
	@${MV} ${WRKDIR}/tl-parser-master/* ${WRKSRC}/tgl/tl-parser

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/telegram-cli
	${INSTALL_PROGRAM} ${WRKSRC}/bin/telegram-cli ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${PREFIX}/etc/telegram-cli/server.pub
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGELOG README-LUA README.es README.md \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
