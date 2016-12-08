# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	nbd
PORTVERSION=	3.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF
PKGNAMESUFFIX=	-server

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Server for the Linux network block device (nbd)

LICENSE=	GPLv2

USES=		pkgconfig tar:bzip2
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
