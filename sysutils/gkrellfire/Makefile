# New ports collection makefile for:	gkrellfire
# Date created:		2004-07-16
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	gkrellfire
PORTVERSION=	0.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freenet.de/thomas-steinke/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Gkrellm2 plugin which shows the system load as a flame

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/${PORTNAME}.so
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	gkrellfire.so

post-extract:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.so ${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
