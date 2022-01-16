PORTNAME=	e2tools
DISTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@fuz.su
COMMENT=	Utilities to manipulate files in an ext2/ext3 filesystem

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libext2fs.so:sysutils/e2fsprogs

USES=		pkgconfig
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
