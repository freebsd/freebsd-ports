# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	trayicons
PORTVERSION=	1.03
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://tripie.sweb.cz/gkrellm/trayicons/dist/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM2 plugin to display definable icons as notifiers or launchers

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USES=		pkgconfig

ALL_TARGET=	trayicons.so

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CC) $$(FLAGS)|$$(CC) $$(CFLAGS)|g' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.so ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
