# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	telegram-cli
DISTVERSION=	1.0.5.1
CATEGORIES=	net-im

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Telegram CLI messaging client

LICENSE=	GPLv2

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig

USE_GITHUB=	yes
GH_ACCOUNT=	vysheng
GH_COMMIT=	77bbb4c
GH_TAGNAME=	1.0.5.1
GH_PROJECT=	tg
USES=		libtool execinfo lua gmake
HAS_CONFIGURE=	yes
PLIST_FILES=	bin/telegram-cli \
		etc/telegram-cli/server.pub

.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/telegram-cli ${STAGEDIR}${LOCALBASE}/bin/telegram-cli
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/telegram-cli
	${INSTALL_DATA} ${WRKSRC}/tg-server.pub ${STAGEDIR}${LOCALBASE}/etc/telegram-cli/server.pub

.include <bsd.port.post.mk>
