# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	gkrellmlaunch
PORTVERSION=	0.5
PORTREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application launcher plugin for GKrellM2

LICENSE=	GPLv2+

BUILD_DEPENDS=	gkrellm2>0:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm2>0:sysutils/gkrellm2

USES=		pkgconfig
ALL_TARGET=	gkrellmlaunch.so

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmlaunch.so

post-patch:
	@${REINPLACE_CMD} -e \
		'/^FLAGS/s|-O[0-9]|| ; \
		 /^FLAGS/s|-g|| ; \
		 /^CC/s| =| +=| ; \
		 /^CC/s|gcc||' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	(cd ${WRKSRC} && ${INSTALL_LIB} gkrellmlaunch.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins)

.include <bsd.port.mk>
