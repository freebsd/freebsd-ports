# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	scalpel
PORTVERSION=	2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.digitalforensicssolutions.com/Scalpel/ \
		https://fossies.org/linux/misc/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Frugal, high performance file carver

LICENSE=	GPLv2

LIB_DEPENDS=	libtre.so:textproc/libtre

USES=		alias
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	etc/scalpel.conf.sample bin/scalpel man/man1/scalpel.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's/#ifdef __APPLE__/#if defined(__APPLE__) || defined(__FreeBSD__)/' \
		${WRKSRC}/src/scalpel.h

post-install:
	@${CP} -p ${WRKSRC}/scalpel.conf ${STAGEDIR}${PREFIX}/etc/scalpel.conf.sample

.include <bsd.port.mk>
