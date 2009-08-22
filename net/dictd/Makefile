# ex:ts=8
# New ports collection makefile for:	dictd
# Date created:		Jan 23, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dictd
PORTVERSION=	1.11.1
CATEGORIES+=	net textproc
MASTER_SITES=	SF/dict/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	clsung@FreeBSD.org
COMMENT=	Dict protocol (RFC 2229) server

LIB_DEPENDS=	maa.1:${PORTSDIR}/devel/libmaa

MAN1=		dictzip.1
MAN8=		dictd.8

USE_RC_SUBR=	${PORTNAME}.sh
USE_BISON=	build
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--without-local-zlib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

SUB_FILES+=	pkg-message
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
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/${PORTNAME}.conf > ${PREFIX}/etc/${PORTNAME}.conf.sample
	@[ -f ${PREFIX}/etc/${PORTNAME}.conf ] || ${CP} ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
