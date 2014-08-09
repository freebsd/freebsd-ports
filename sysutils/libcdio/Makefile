# Created by: arved
# $FreeBSD$

PORTNAME=	libcdio
PORTVERSION=	0.92
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libcdio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library

LIB_DEPENDS=	libcddb.so:${PORTSDIR}/audio/libcddb

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig iconv libtool ncurses gmake perl5
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG}
USE_PERL5=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

INFO=		libcdio

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,freebsd5\.\*,freebsd*," ${WRKSRC}/configure

.include <bsd.port.post.mk>
