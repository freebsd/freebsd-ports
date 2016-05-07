# Created by: arved
# $FreeBSD$

PORTNAME=	libcdio
PORTVERSION=	0.93
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library

LIB_DEPENDS=	libcddb.so:audio/libcddb

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		cpe pathfix pkgconfig iconv libtool ncurses gmake perl5
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG}
USE_PERL5=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

INFO=		libcdio
CPE_VENDOR=	gnu
INSTALL_TARGET=install-strip 

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,freebsd5\.\*,freebsd*," ${WRKSRC}/configure

.include <bsd.port.post.mk>
