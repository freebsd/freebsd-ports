# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dictd
PORTVERSION=	1.12.1
CATEGORIES+=	net textproc
MASTER_SITES=	SF/dict/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	clsung@FreeBSD.org
COMMENT=	Dict protocol (RFC 2229) server

LIB_DEPENDS=	maa.3:${PORTSDIR}/devel/libmaa

MAN1=		dictzip.1
MAN8=		dictd.8

USE_RC_SUBR=	${PORTNAME}
USES=		bison
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--without-local-zlib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES+=	dictd.conf pkg-message
SUB_LIST+=	PORTSDIR=${PORTSDIR}

USE_GMAKE=	yes

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip

post-patch:
.for i in Makefile.in dict.1.in dictd.8.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$i
.endfor
	@${REINPLACE_CMD} -e "s|\([\ \t(]\)T_USER|\1T_USERNAME|g" ${WRKSRC}/*.[chly]

post-install:
	@${CP} ${WRKDIR}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@[ -f ${PREFIX}/etc/${PORTNAME}.conf ] || ${CP} ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
