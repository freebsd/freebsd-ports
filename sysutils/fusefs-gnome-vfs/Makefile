# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fusefs-gnome-vfs
PORTVERSION=	0.1
PORTREVISION=	6
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.evolware.org/chri/
DISTNAME=	${RPORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface between FUSE and the Gnome VFS 2.0

RPORTNAME=	gnome-vfs-fuse
WRKSRC=		${WRKDIR}/${RPORTNAME}
USES=		fuse pkgconfig gmake
USE_GNOME=	gnomevfs2
PLIST_FILES=	bin/gnomevfs-mount
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnomevfs-mount ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
