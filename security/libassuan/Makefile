# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libassuan
PORTVERSION=	2.1.2
CATEGORIES=	security devel
MASTER_SITES=	GNUPG/${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	IPC library used by GnuPG and gpgme

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgpg-error.so:${PORTSDIR}/security/libgpg-error

USES=		libtool:keepla tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		assuan

.include <bsd.port.mk>
