# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gputty
PORTVERSION=	0.9.10
CATEGORIES=	security
MASTER_SITES=	http://www.defora.org/os/download/download/3381/

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Frontend to the SSH client, using the Gtk+ toolkit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem

PLIST_FILES=	bin/gputty

MAKE_ARGS=	PREFIX=${PREFIX}
USES=		gnome pkgconfig
USE_GNOME=	gtk20

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
