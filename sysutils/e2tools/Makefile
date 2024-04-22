PORTNAME=	e2tools
DISTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Utilities to manipulate files in an ext2/ext3 filesystem
WWW=		https://e2tools.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libext2fs.so:sysutils/e2fsprogs-core

USES=		pkgconfig
GNU_CONFIGURE_MANPREFIX=        ${PREFIX}/share
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
