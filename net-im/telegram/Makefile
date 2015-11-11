# Created by: gahr
# $FreeBSD$

PORTNAME=	telegram
PORTVERSION=	1.3.1
CATEGORIES=	net-im

MAINTAINER=	cpm@fbsd.es
COMMENT=	Command-line interface for Telegram

LICENSE=	GPLv2

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig \
    		libevent.so:${PORTSDIR}/devel/libevent2 \
		libjansson.so:${PORTSDIR}/devel/jansson

USES=		execinfo gmake lua:52 ncurses pkgconfig readline
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	vysheng
GH_PROJECT=	tg:telegram tgl tl-parser:tlparser
GH_TAGNAME=	1.3.1:telegram 2.0.1 1659d87:tlparser

WRKSRC=		${WRKDIR}/tg-1.3.1

PLIST_FILES=	bin/telegram-cli \
		etc/telegram-cli/server.pub
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
USE_GCC=	yes
.endif

post-extract:
	@${RM} -r ${WRKSRC}/tgl
	@${MV} ${WRKDIR}/tgl-2.0.1 ${WRKSRC}/tgl
	@${MV} ${WRKDIR}/tl-parser-1659d87/* ${WRKSRC}/tgl/tl-parser
	@${RM} -r ${WRKDIR}/tl-parser-1659d87

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/telegram-cli
	${INSTALL_PROGRAM} ${WRKSRC}/bin/telegram-cli ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${PREFIX}/etc/telegram-cli/server.pub
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGELOG README-LUA README.es README.md \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
