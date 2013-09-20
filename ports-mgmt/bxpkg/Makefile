# Created by: Kostas Petrikas <kpetrikas@gmail.com>
# $FreeBSD$

PORTNAME=	bxpkg
DISTVERSION=	0.0.4_0
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://bxpkg.bsdroot.lv/files/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	kpetrikas@gmail.com
COMMENT=	bxPKG is a GTK+ based tool to manage binary packages on BSD systems.

USES=		pkgconfig
USE_XORG=	x11
USE_GNOME=	gtk20

PLIST_FILES=	bin/bxpkg
USE_BZIP2=	YES

WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
LIB_DEPENDS+=	archive:${PORTSDIR}/archivers/libarchive
.endif

.include <bsd.port.post.mk>
