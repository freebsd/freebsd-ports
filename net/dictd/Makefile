# ex:ts=8
# New ports collection makefile for:	dictd
# Date created:		Jan 23, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dictd
PORTVERSION=	1.5.5
CATEGORIES=	net textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/

MAINTAINER=	ijliao@FreeBSD.org

MAN1=		dictzip.1
MAN8=		dictd.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX} --with-cflags=${CFLAGS} --with-etcdir=${PREFIX}/etc"
USE_GMAKE=	yes

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip

post-patch:
.for i in dict.1 dictd.8
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$i
.endfor
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${PKGMESSAGE}
.for i in dictd.conf example.conf
	@${PERL} -pi -e "s|/usr|${PREFIX}|g" ${WRKSRC}/$i
.endfor

post-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
.for i in example.conf example.dictrc example.site example2.conf example3.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/${PORTNAME}
.endfor
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/dictd.sh > ${PREFIX}/etc/rc.d/dictd.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/dictd.sh
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${PKGMESSAGE}

.include <bsd.port.mk>
