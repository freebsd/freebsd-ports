# Created by: Chris Stuart <firewolf@lightningfire.net>
# $FreeBSD$

PORTNAME=	gkrellmbgchg2
PORTVERSION=	0.1.11
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.bender-suhl.de/stefan/comp/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for GKrellM, which changes the desktop's background image

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		gmake gnome pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmbgchg.so

PLUGINDIR=	${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

do-install:
	@${MKDIR} ${PLUGINDIR}
	${INSTALL_LIB} ${WRKSRC}/gkrellmbgchg.so ${PLUGINDIR}

.include <bsd.port.mk>
