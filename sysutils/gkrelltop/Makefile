# New ports collection makefile for:	gkrelltop
# Date created:				12 April 2004
# Whom:					David Gardner
#
# $FreeBSD$
#

PORTNAME=	gkrelltop
PORTVERSION=	2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://psychology.rutgers.edu/~zaimi/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@pinko.net
COMMENT=	Plugin for gkrellm 2.x shows top three processes, requires procfs

RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2
BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2

MAKE_ARGS=	INSTALLDIR2=${PREFIX}/libexec/gkrellm2/plugins
INSTALL_TARGET=	install2
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	libexec/gkrellm2/plugins/gkrelltop2.so

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
