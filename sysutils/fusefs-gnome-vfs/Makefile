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
USES=		fuse pkgconfig
USE_GNOME=	gnomevfs2
USE_GMAKE=	yes
PLIST_FILES=	bin/gnomevfs-mount
PORTDOCS=	README

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnomevfs-mount ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
