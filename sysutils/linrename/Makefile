PORTNAME=	linrename
PORTVERSION=	2.25.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${PORTVERSION:R}
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename multiple files using substitution
WWW=		http://freecode.com/projects/util-linux/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	FreeBSD port unmaintained, use misc/mmv instead
EXPIRATION_DATE=2025-09-30

USES=		tar:xz

CPPFLAGS+=	-I../include \
		-DHAVE_DIRFD -DHAVE_ERR_H -DHAVE_LANGINFO_H -DHAVE_LOCALE_H \
		-DHAVE_NANOSLEEP -DHAVE_FSYNC \
		-DHAVE_PROGRAM_INVOCATION_SHORT_NAME \
		-Dprogram_invocation_short_name=\"${PROGNAME}\" \
		-DPACKAGE_STRING=\"util-linux\ ${PORTVERSION}\"

BUILD_WRKSRC=	${WRKSRC}/misc-utils
INSTALL_WRKSRC=	${WRKSRC}/misc-utils

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

post-patch:
	${LN} -sf rename.1 ${BUILD_WRKSRC}/${PORTNAME}.1
	${REINPLACE_CMD} 's/rename(1)/${PORTNAME}(1)/' ${BUILD_WRKSRC}/rename.c

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} \
		rename.c ${LDFLAGS}

do-install:
	cd ${INSTALL_WRKSRC} \
		&& ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin \
		&& ${INSTALL_MAN} ${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
