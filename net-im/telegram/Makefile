# Created by: gahr
# $FreeBSD$

PORTNAME=	telegram
PORTVERSION=	1.3.1
CATEGORIES=	net-im

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Command-line interface for Telegram

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libevent.so:devel/libevent2 \
		libjansson.so:devel/jansson

BROKEN_mips=	Missing header
BROKEN_mips64=	Missing header
BROKEN_powerpc64=	Does not build

USES=		execinfo gmake lua:52 ncurses pkgconfig readline
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	vysheng
GH_PROJECT=	tg tgl:tgl tl-parser:tlparser
GH_TAGNAME=	1.3.1 2.0.1:tgl 1659d87:tlparser

PLIST_FILES=	bin/telegram-cli \
		etc/telegram-cli/server.pub
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
USE_GCC=	yes
.endif

post-extract:
	@${MV} ${WRKSRC_tgl}/* ${WRKSRC}/tgl
	@${MV} ${WRKSRC_tlparser}/* ${WRKSRC}/tgl/tl-parser

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/telegram-cli
	${INSTALL_PROGRAM} ${WRKSRC}/bin/telegram-cli ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${PREFIX}/etc/telegram-cli/server.pub
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGELOG README-LUA README.es README.md \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
