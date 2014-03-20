# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	gkrellfire
PORTVERSION=	0.4.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://freenet-homepage.de/thomas-steinke/ \
		LOCAL
MASTER_SITE_SUBDIR=	novel
EXTRACT_SUFX=	.tgz

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Gkrellm2 plugin which shows the system load as a flame

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/${PORTNAME}.so
PLIST_DIRSTRY=	libexec/gkrellm2/plugins libexec/gkrellm2

USES=		gmake pkgconfig
MAKE_ARGS=	CC="${CC}"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
