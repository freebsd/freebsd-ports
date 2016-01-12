# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libquantum
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.libquantum.de/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for quantum computing and quantum simulation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes

PLIST_FILES=	include/quantum.h \
		lib/libquantum.a \
		lib/libquantum.so \
		lib/libquantum.so.8 \
		lib/libquantum.so.8.0.0

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libquantum.so

.include <bsd.port.mk>
