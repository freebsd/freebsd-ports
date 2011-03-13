# New ports collection makefile for:	busybox
# Date created:         Aug.18, 2008
# Whom:                 luigi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	busybox
PORTVERSION=	1.18.4
CATEGORIES=	sysutils misc shells
MASTER_SITES=	http://www.busybox.net/downloads/ \
		http://distfiles.gentoo.org/distfiles/

MAINTAINER=	utisoft@gmail.com
COMMENT=	Busybox for FreeBSD

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/busybox

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/sed/gsed/' ${WRKSRC}/scripts/gen_build_files.sh
	@${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/libbb/appletlib.c \
		${WRKSRC}/shell/hush.c

do-configure:
	${CP} ${FILESDIR}/data-.config ${WRKSRC}/.config
	cd ${WRKSRC} && ${GMAKE} oldconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
