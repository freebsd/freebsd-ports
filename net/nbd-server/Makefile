# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	nbd
PORTVERSION=	3.20
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF
PKGNAMESUFFIX=	-server

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Server for the Linux network block device (nbd)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lfs --enable-syslog
TEST_TARGET=	check

OPTIONS_DEFINE=	GNUTLS
GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_BUILD_DEPENDS=	gnutls>0:security/gnutls
GNUTLS_RUN_DEPENDS=	gnutls>0:security/gnutls

PLIST_FILES=	bin/nbd-server bin/nbd-trdump \
		man/man1/nbd-server.1.gz \
		man/man1/nbd-trdump.1.gz \
		man/man5/nbd-server.5.gz \
		man/man5/nbdtab.5.gz \
		man/man8/nbd-client.8.gz

.include <bsd.port.mk>
