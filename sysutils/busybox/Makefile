# New ports collection makefile for:	busybox
# Date created:         Aug.18, 2008
# Whom:                 luigi@FreeBSD.org
#
# Maintainers:		Luigi Rizzo <luigi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	busybox
PORTVERSION=	1.13.4
CATEGORIES=	sysutils misc shells
MASTER_SITES=	http://www.busybox.net/downloads/ \
		http://distfiles.gentoo.org/distfiles/

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	Busybox for FreeBSD

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/busybox

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		does not compile
.elif ${OSVERSION} >= 800000
BROKEN=		does not compile
.endif

do-configure:
	${CP} ${FILESDIR}/data-.config ${WRKSRC}/.config
	cd ${WRKSRC} && ${GMAKE} oldconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
