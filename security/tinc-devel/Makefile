# $FreeBSD$

PORTNAME=	tinc
PORTVERSION=	1.1pre17
PORTREVISION=	4
CATEGORIES=	security net-vpn
MASTER_SITES=	https://www.tinc-vpn.org/packages/ \
		http://www.tinc-vpn.org/packages/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Virtual Private Network (VPN) daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		cpe ssl makeinfo readline localbase:ldflags
CPE_VENDOR=	tinc-vpn
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --with-curses=/usr
USE_RC_SUBR=	tincd
INFO=		tinc
PLIST_FILES=	sbin/tincd sbin/tinc \
		man/man8/tinc-gui.8.gz man/man5/tinc.conf.5.gz \
		man/man8/tinc.8.gz man/man8/tincd.8.gz

.include <bsd.port.mk>
