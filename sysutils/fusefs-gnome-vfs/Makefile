# New ports collection makefile for:	fusefs-gnome-vfs
# Date created:		2006-12-23
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fusefs-gnome-vfs
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.evolware.org/chri/
DISTNAME=	${RPORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface between FUSE and the Gnome VFS 2.0

RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs

RPORTNAME=	gnome-vfs-fuse
WRKSRC=		${WRKDIR}/${RPORTNAME}
USE_GNOME=	gnomevfs2
USE_GMAKE=	yes
PLIST_FILES=	bin/gnomevfs-mount
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnomevfs-mount ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
