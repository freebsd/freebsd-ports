# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	gkrellm-helium
PORTVERSION=	2.3.1
PORTREVISION=	12
CATEGORIES=	misc
MASTER_SITES=	https://sites.google.com/site/makovick/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin reading data from helium thermometer at Strahov, Prague

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		pkgconfig tar:tgz

PLIST_FILES=	libexec/gkrellm2/plugins/helium.so

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/lib/gkrellm2|${STAGEDIR}${PREFIX}/libexec/gkrellm2| ; \
		 /^CFLAGS/s| =.*| += -fPIC `pkg-config libcurl --cflags`| ; \
		 s|gcc |$$(CC) | ; \
		 s|-lcurl|`pkg-config libcurl --libs`|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|ulong|u_long|' ${WRKSRC}/*.c
	@${REINPLACE_CMD} -e \
		'/<curl\/types.h>/d' ${WRKSRC}/http_net.c

.include <bsd.port.mk>
