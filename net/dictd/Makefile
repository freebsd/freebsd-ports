# ex:ts=8
# New ports collection makefile for:	dictd
# Date created:		Jan 23, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dictd
PORTVERSION=	1.10.1
PORTREVISION=	0
CATEGORIES+=	net textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=		dict

MAINTAINER?=	dd@FreeBSD.org
COMMENT=	Dict protocol (RFC 2229) server

MAN1=		dictzip.1
MAN8=		dictd.8

USE_RC_SUBR=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--without-local-zlib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

USE_GMAKE=	yes

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip

post-patch:
.for i in Makefile.in dict.1 dictd.8
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$i
.endfor
.for i in example.conf
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|g" ${WRKSRC}/$i
.endfor
	@${REINPLACE_CMD} -e "s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/zlib/Makefile
	@${REINPLACE_CMD} -e "s|\([\ \t(]\)T_USER|\1T_USERNAME|g" ${WRKSRC}/*.[chly]

post-install:
	@${MKDIR} ${DATADIR}
.for i in example.conf example.dictrc example.site example2.conf example3.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}
.endfor
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/${PORTNAME}.conf > ${PREFIX}/etc/${PORTNAME}.conf.sample
	@[ -f ${PREFIX}/etc/${PORTNAME}.conf ] || ${CP} ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${FILESDIR}/${PORTNAME}.sh > ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${PKGMESSAGE}

.include <bsd.port.mk>
