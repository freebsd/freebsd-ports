PORTNAME=	sg3_utils
DISTVERSION=	1.49
CATEGORIES=	sysutils
MASTER_SITES=	https://sg.danny.cz/sg/p/

PATCH_SITES=	https://github.com/doug-gilbert/sg3_utils/commit/
PATCHFILES=	958434a1d2b5b2f4f465c9196c3c4ecf362eeb22.patch:-p1 \
		c32e19f52e7b5c75bd2a9b222c072eef16a4e583.patch:-p1 \
		c60834d53313f3796f43fdf874db98a9e8b03b6e.patch:-p1 \
		840637b1c402a02ea56a5447fb616200f5314a51.patch:-p1

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Set of utilities that send SCSI commands to devices
WWW=		https://sg.danny.cz/sg/sg3_utils.html

LICENSE=	BSD2CLAUSE GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/BSD_LICENSE
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

USES=		cmake shebangfix tar:xz
SHEBANG_FILES=	scripts/*
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
