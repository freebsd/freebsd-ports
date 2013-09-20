# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	nbd
PORTVERSION=	3.3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF
PKGNAMESUFFIX=	-server

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for the Linux network block device (nbd)

USE_BZIP2=	yes
USE_GNOME=	glib20
USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lfs --enable-syslog

PLIST_FILES=	bin/nbd-server bin/nbd-trdump
MAN1=		nbd-server.1 nbd-trdump.1
MAN5=		nbd-server.5
MAN8=		nbd-client.8

regression-test: build
		cd ${WRKSRC} && ${MAKE} check

NO_STAGE=	yes
.include <bsd.port.mk>
