PORTNAME=	libpri
PORTVERSION=	1.6.1
CATEGORIES=	misc
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/libpri/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C implementation of the Primary Rate ISDN specification
WWW=		https://www.asterisk.org/downloads/libpri/

LICENSE=	GPLv2

USES=		gmake
USE_LDCONFIG=	yes
PLIST_FILES=	include/libpri.h lib/libpri.a lib/libpri.so lib/libpri.so.1
MAKE_ARGS=	INSTALL_PREFIX=${STAGEDIR}${PREFIX}

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc powerpc64 powerpc64le

post-patch:
	${REINPLACE_CMD} -e '/^all:/s/$$(UTILITIES)//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
