# New ports collection makefile for:    netshow
# Date created:         Thu Jun 11 22:38:52 PDT 1998
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netshow
PORTVERSION=	2.00.251
PORTREVISION=	1
CATEGORIES=	multimedia linux net
MASTER_SITES=	http://www.microsoft.com/netshow/download/en/beta/
DISTNAME=	netshow_linux
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Microsoft NetShow video stream player

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

RESTRICTED=	"Commercial software"
BROKEN=		Unfetchable

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/netshow

NO_BUILD=	yes
USE_X_PREFIX=	yes

pre-extract:
	@${MKDIR} ${WRKDIR}

do-extract:
	${GUNZIP_CMD} < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/netshow

do-patch:
	brandelf -t Linux ${WRKDIR}/netshow

do-install:
	${INSTALL} -c -o bin -g bin -m 555 ${WRKDIR}/netshow ${PREFIX}/bin/netshow

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
