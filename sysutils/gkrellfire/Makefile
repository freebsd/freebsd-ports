# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	gkrellfire
PORTVERSION=	0.4.2
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://freenet-homepage.de/thomas-steinke/ \
		LOCAL/novel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gkrellm2 plugin which shows the system load as a flame

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/${PORTNAME}.so

USES=		gmake pkgconfig tar:tgz
MAKE_ARGS=	CC="${CC}"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
