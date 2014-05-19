# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dictd
PORTVERSION=	1.12.1
CATEGORIES+=	net textproc
MASTER_SITES=	SF/dict/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	clsung@FreeBSD.org
COMMENT=	Dict protocol (RFC 2229) server

LICENSE=	GPLv2

LIB_DEPENDS=	libmaa.so:${PORTSDIR}/devel/libmaa

USE_RC_SUBR=	${PORTNAME}
USES=		bison libtool gmake
USE_AUTOTOOLS=	libtoolize
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--without-local-zlib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES+=	dictd.conf pkg-message
SUB_LIST+=	PORTSDIR=${PORTSDIR}

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip

post-patch:
.for i in Makefile.in dict.1.in dictd.8.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$i
.endfor
	@${REINPLACE_CMD} -e "s|\([\ \t(]\)T_USER|\1T_USERNAME|g" ${WRKSRC}/*.[chly]

post-install:
	@${CP} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
