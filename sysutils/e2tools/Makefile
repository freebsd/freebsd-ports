PORTNAME=	e2tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	fuz@fuz.su
COMMENT=	Utilities to manipulate files in an ext2/ext3 filesystem

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libext2fs.so:sysutils/e2fsprogs

USES=		autoreconf pkgconfig
USE_GITHUB=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
