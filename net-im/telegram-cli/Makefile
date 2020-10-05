# Created by: gahr
# $FreeBSD$

PORTNAME=	telegram-cli
DISTVERSION=	20200106
CATEGORIES=	net-im

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line interface for Telegram

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libevent.so:devel/libevent \
		libjansson.so:devel/jansson

USES=		gmake lua pkgconfig readline ssl
USE_GITHUB=	yes
GH_ACCOUNT=	kenorb-contrib
GH_PROJECT=	tg
GH_TUPLE=	kenorb-contrib:tgl:57f1bc4:tgl/tgl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-python

CFLAGS+=	-fcommon

CONFLICTS_INSTALL=	telegram

PLIST_FILES=	${ETCDIR}/server.pub \
		bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGELOG README-LUA README.es README.md

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${ETCDIR}/server.pub
	${INSTALL_MAN} ${WRKSRC}/telegram.1 ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
