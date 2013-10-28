# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	nbd
PORTVERSION=	3.4
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF
PKGNAMESUFFIX=	-server

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for the Linux network block device (nbd)

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lfs --enable-syslog

PLIST_FILES=	bin/nbd-server bin/nbd-trdump \
		man/man1/nbd-server.1.gz \
		man/man1/nbd-trdump.1.gz \
		man/man5/nbd-server.5.gz \
		man/man8/nbd-client.8.gz

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
