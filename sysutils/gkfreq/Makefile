PORTNAME=	gkrellm-gkfreq
PORTVERSION=	2.2
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Plugin to GKrellM that displays the current CPU frequencies

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gkrellm.pc:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		pkgconfig

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellm-gkfreq.so

PLUGIN_DIR=	${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

MAKE_ENV+=	PLUGIN_DIR=${PLUGIN_DIR}

pre-install:
	@${MKDIR} ${PLUGIN_DIR}

.include <bsd.port.mk>
