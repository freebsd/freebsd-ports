# Created by: Alexander Timoshenko <gonzo@univ.kiev.ua>
# $FreeBSD$

PORTNAME=	libpri
PORTVERSION=	1.4.13
CATEGORIES=	misc
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/libpri/releases/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	C implementation of the Primary Rate ISDN specification

LICENSE=	GPLv2

USES=		gmake
USE_LDCONFIG=	yes
PLIST_FILES=	include/libpri.h lib/libpri.a lib/libpri.so lib/libpri.so.1
MAKE_ARGS=	INSTALL_PREFIX=${STAGEDIR}${PREFIX}


ONLY_FOR_ARCHS=	amd64 i386 sparc64

post-patch:
	${REINPLACE_CMD} -e '/^all:/s/$$(UTILITIES)//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
