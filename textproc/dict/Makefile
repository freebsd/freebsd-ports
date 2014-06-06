# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	dict
PORTVERSION=	1.12.1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}d/${PORTNAME}d-${PORTVERSION}
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Dictionary Server Protocol (RFC2229) client

LICENSE=	GPLv2

LIB_DEPENDS=	libmaa.so:${PORTSDIR}/devel/libmaa

USES=		bison gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-local-zlib --with-cflags="${CFLAGS}" \
		--with-etcdir=${PREFIX}/etc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_AUTOTOOLS=	libtoolize
ALL_TARGET=	dict
INSTALL_TARGET=	install.dict

post-patch:
	${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/dict.1.in

post-configure:
	${REINPLACE_CMD} -e 's|^        mkdir|	mkdir|g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${FILESDIR}/dict.conf ${STAGEDIR}${PREFIX}/etc/dict.conf.sample

.include <bsd.port.mk>
