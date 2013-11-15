# Created by: Jonathan Liu <Net147@hotmail.com>
# $FreeBSD$

PORTNAME=	linrename
PORTVERSION=	2.22.2
CATEGORIES=	sysutils
#MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${PORTVERSION}
MASTER_SITES=	http://ftp.ntu.edu.tw/ftp/linux/%SUBDIR%/ \
		http://ftp.sunet.se/pub/Linux/kernel.org/linux/%SUBDIR%/ \
		http://kernel.org/pub/linux/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,linux/kernel.org/&,}
MASTER_SITE_SUBDIR=	utils/util-linux/v${PORTVERSION:R}
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename multiple files using substitution

BUILD_WRKSRC=	${WRKSRC}/misc-utils
INSTALL_WRKSRC=	${WRKSRC}/misc-utils

USE_XZ=		yes

CPPFLAGS+=	-I../include \
		-DHAVE_DIRFD -DHAVE_ERR_H -DHAVE_LANGINFO_H -DHAVE_LOCALE_H \
		-DPACKAGE_STRING=\"util-linux\ ${PORTVERSION}\"

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-patch:
	${LN} -sf rename.1 ${BUILD_WRKSRC}/${PORTNAME}.1

do-build:
	(cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} \
		rename.c ${LDFLAGS})

do-install:
	(cd ${INSTALL_WRKSRC} \
		&& ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin \
		&& ${INSTALL_MAN} ${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
