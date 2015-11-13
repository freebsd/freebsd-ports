# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dictd
PORTVERSION=	1.12.1
CATEGORIES+=	net textproc
MASTER_SITES=	SF/dict/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dict protocol (RFC 2229) server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmaa.so:${PORTSDIR}/devel/libmaa

ALL_TARGET=	dictd dictzip
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install.dictd install.dictzip
USES=		bison gmake libtool:build localbase

SUB_FILES=	dictd.conf pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}
USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile.in ${WRKSRC}/dict.1.in ${WRKSRC}/dictd.8.in
	@${REINPLACE_CMD} -e "s|\([\ \t(]\)T_USER|\1T_USERNAME|g" ${WRKSRC}/*.[chly]

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
