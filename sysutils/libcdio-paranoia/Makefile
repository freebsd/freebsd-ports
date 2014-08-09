# $FreeBSD$

PORTNAME=	libcdio-paranoia
PORTVERSION=	10.2+0.90+1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libcdio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Read audio from the CDROM directly as data

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL

LIB_DEPENDS=	libcdio.so:${PORTSDIR}/sysutils/libcdio

USES=	pathfix tar:bzip2 gmake pkgconfig libtool perl5
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|/jp/man1|/ja/man1|' \
		${WRKSRC}/doc/ja/Makefile.in

.include <bsd.port.mk>
