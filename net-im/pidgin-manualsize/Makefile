# Created by: Joseph S. Atkinson <jsatkinson@embarqmail.com>
# $FreeBSD$

PORTNAME=	manualsize
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	http://issv.org.ru/oss/ \
		http://wickedmachine.net/~jsa/FreeBSD/distfiles/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to allow manual resizing of Pidgin's message input area

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

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
