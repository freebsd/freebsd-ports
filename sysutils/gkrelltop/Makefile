# New ports collection makefile for:	gkrelltop
# Date created:				12 April 2004
# Whom:					David Gardner
#
# $FreeBSD$
#

PORTNAME=	gkrelltop
PORTVERSION=	2.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://psychology.rutgers.edu/~zaimi/html/gkrelltop/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@pinko.net
COMMENT=	Plugin for gkrellm 2.x shows top three processes, requires procfs

RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2
BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2

USE_GMAKE=	yes
MAKE_ARGS=	INSTALLDIR=${PREFIX}/libexec/gkrellm2/plugins \
		INSTALLDIRD=${PREFIX}/libexec/gkrellm2/plugins
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	libexec/gkrellm2/plugins/gkrelltop.so \
		libexec/gkrellm2/plugins/gkrelltopd.so

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
