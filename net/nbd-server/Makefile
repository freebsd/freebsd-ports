PORTNAME=	nbd
DISTVERSION=	3.27.0
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/NetworkBlockDevice/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/
PKGNAMESUFFIX=	-server

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Server for the Linux network block device (nbd)
WWW=		https://github.com/NetworkBlockDevice/nbd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison:wrapper cpe gmake gnome pkgconfig tar:xz
CPE_VENDOR=	wouter_verhelst
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lfs --enable-syslog --disable-manpages

TEST_TARGET=	check

PLIST_FILES=	bin/nbd-server bin/nbd-trdump bin/nbd-trplay

OPTIONS_DEFINE=	GNUTLS

GNUTLS_BUILD_DEPENDS=	gnutls>0:security/gnutls
GNUTLS_RUN_DEPENDS=	gnutls>0:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

.include <bsd.port.mk>
