# ex:ts=8
# New ports collection makefile for:	dictd
# Date created:		Jan 23, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dictd
PORTVERSION=	1.5.5
PORTREVISION=	2
CATEGORIES=	net textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/dict/wn.index:${PORTSDIR}/net/dictd-database

MAN1=		dictzip.1
MAN8=		dictd.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}"
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"
USE_GMAKE=	yes

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip

post-patch:
.for i in dict.1 dictd.8
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$i
.endfor
.for i in example.conf
	@${PERL} -pi -e "s|/usr|${PREFIX}|g" ${WRKSRC}/$i
.endfor
	@${PERL} -pi -e "s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/zlib/Makefile
	@${PERL} -pi -e "s|[\ \t]T_USER| T_USERNAME|g" ${WRKSRC}/*.[chly]

post-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
.for i in example.conf example.dictrc example.site example2.conf example3.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/${PORTNAME}
.endfor
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/${PORTNAME}.conf > ${PREFIX}/etc/${PORTNAME}.conf
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/${PORTNAME}.sh > ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${PKGMESSAGE}

.include <bsd.port.mk>
