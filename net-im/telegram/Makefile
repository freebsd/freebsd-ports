# Created by: gahr
# $FreeBSD$

PORTNAME=	telegram
PORTVERSION=	1.4.1.g20161227
PORTREVISION=	7
CATEGORIES=	net-im

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line interface for Telegram

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=	Missing header
BROKEN_mips64=	Missing header
BROKEN_powerpc64=	Does not build: Assertion failed: (get_int () == TLS_SCHEMA_V2)

DEPRECATED=	Upstream unmaintained; please migrate to net-im/telegram-cli
EXPIRATION_DATE=	2021-01-14

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libevent.so:devel/libevent \
		libjansson.so:devel/jansson

USES=		gmake lua:52 pkgconfig readline ssl
USE_GITHUB=	yes
GH_ACCOUNT=	vysheng
GH_PROJECT=	tg tgl:tgl tl-parser:tlparser
GH_SUBDIR=	tgl:tgl tgl/tl-parser:tlparser
GH_TAGNAME=	6547c0b ffb04ca:tgl 36bf190:tlparser

CFLAGS+=	-fcommon

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	telegram-cli

PLIST_FILES=	bin/telegram-cli \
		etc/telegram-cli/server.pub
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-openssl-1.1.0
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/telegram-cli
	${INSTALL_PROGRAM} ${WRKSRC}/bin/telegram-cli ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${PREFIX}/etc/telegram-cli/server.pub
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGELOG README-LUA README.es README.md \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
