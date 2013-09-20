# Created by: Andrew Stuart <elitetek@tekrealm.net>
# $FreeBSD$

PORTNAME=	gkrellshoot
PORTVERSION=	0.3.2
PORTREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Screen locking and screen capture plugin for GKrellM

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm \
		import:${PORTSDIR}/graphics/ImageMagick

PLIST_FILES=	libexec/gkrellm/plugins/gkrellshoot.so
WRKSRC=		${WRKDIR}/gkrellShoot-${PORTVERSION}
USE_GNOME=	imlib

NO_STAGE=	yes
.include <bsd.port.mk>
