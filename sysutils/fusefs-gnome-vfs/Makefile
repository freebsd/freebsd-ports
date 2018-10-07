# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fusefs-gnome-vfs
PORTVERSION=	0.1
PORTREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.evolware.org/chri/
DISTNAME=	${RPORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface between FUSE and the Gnome VFS 2.0

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	GNOME 2 application
EXPIRATION_DATE=	2018-12-10

RPORTNAME=	gnome-vfs-fuse
WRKSRC=		${WRKDIR}/${RPORTNAME}
USES=		fuse pkgconfig gmake
USE_GNOME=	gnomevfs2

PLIST_FILES=	bin/gnomevfs-mount
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnomevfs-mount ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
