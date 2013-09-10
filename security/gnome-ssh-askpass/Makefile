# Created by: Mark Hannon <markhannon@optusnet.com.au>
# $FreeBSD$

PORTNAME=	gnome-ssh-askpass
PORTVERSION=	5.8p2
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	OPENBSD/OpenSSH/portable/
DISTNAME=	openssh-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Graphical SSH askpass utility for Gnome2

PORTSCOUT=	skipv:5.9p1 # Will update when FreeBSD version off SSH goes to 5.9p1

WRKSRC=		${WRKDIR}/openssh-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/contrib
ALL_TARGET=	gnome-ssh-askpass2

PLIST_FILES=	bin/gnome-ssh-askpass2
USES=		pkgconfig
USE_GNOME=	gtk20

.include <bsd.port.pre.mk>
CFLAGS+=	${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gnome-ssh-askpass2 ${PREFIX}/bin

.include <bsd.port.post.mk>
