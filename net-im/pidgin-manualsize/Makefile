PORTNAME=	manualsize
PORTVERSION=	0.7
PORTREVISION=	7
CATEGORIES=	net-im
MASTER_SITES=	LOCAL/eugen \
		http://www.grosbein.net/freebsd/distfiles/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Plugin to allow manual resizing of Pidgin's message input area
WWW=		https://developer.pidgin.im/wiki/ThirdPartyPlugins #Third-PartyPlugins

LICENSE=	GPLv2

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

MAKEFILE=	makefile

PLIST_FILES=	lib/pidgin/manualsize.so

USES=		pkgconfig tar:bzip2
ALL_TARGET=	manualsize.so

post-patch:
	@${REINPLACE_CMD} 's/gcc/$$(CC)/' ${WRKSRC}/makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pidgin
	${INSTALL_LIB} ${WRKSRC}/manualsize.so ${STAGEDIR}${PREFIX}/lib/pidgin

.include <bsd.port.mk>
