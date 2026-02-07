PORTNAME=	twa-kmod
PORTVERSION=	20230821
CATEGORIES=	sysutils

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	3ware 9000/9500/9550/9650 series SATA RAID controllers driver
WWW=		https://github.com/dinoex/twa-kmod/

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not yet tested on non amd64
IGNORE_FreeBSD_13=	included in base system
IGNORE_FreeBSD_15=	not supported on FreeBSD 15.x

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	dinoex
PATCH_WRKSRC=	${WRKSRC}/sys/dev/twa
WRKROOT=	${WRKDIR}/${PORTNAME}-${PKGVERSION}
BUILD_WRKSRC=	${WRKSRC}/sys/modules/twa
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV+=	SRCTOP=${WRKSRC}
CFLAGS+=	-Wno-error=unused-but-set-variable
CFLAGS+=	-Wno-error=implicit-int
CFLAGS+=	-I${WRKSRC}/sys
PLIST_FILES=	${KMODDIR}/twa.ko \
		share/man/man4/twa.4.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/share/man/man4/twa.4 ${STAGEDIR}${PREFIX}/share/man/man4/

.include <bsd.port.mk>
