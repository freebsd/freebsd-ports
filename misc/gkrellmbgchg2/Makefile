# New ports collection makefile for:	gkrellmbgchg
# Date Created:			8 Aug 2002
# Whom:				Chris Stuart <firewolf@lightningfire.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellmbgchg2
PORTVERSION=	0.1.6
CATEGORIES=	misc
MASTER_SITES=	http://www.bender-suhl.de/stefan/comp/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plugin for GKrellM, which changes the desktop's background image

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_X_PREFIX=	yes
USE_GNOME=	gtk20

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmbgchg.so

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_DATA} ${WRKSRC}/gkrellmbgchg.so \
		${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.post.mk>
