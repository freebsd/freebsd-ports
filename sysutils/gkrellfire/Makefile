# New ports collection makefile for:	gkrellfire
# Date created:		2004-07-16
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	gkrellfire
PORTVERSION=	0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freenet.de/thomas-steinke/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel
EXTRACT_SUFX=	.tgz

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Gkrellm2 plugin which shows the system load as a flame

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/${PORTNAME}.so
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.so ${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
