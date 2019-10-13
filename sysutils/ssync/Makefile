# Created by: Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
# $FreeBSD$

PORTNAME=	ssync
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://linuxfocus.org/~guido/

MAINTAINER=	samm@freebsd.org
COMMENT=	Minimalistic tool for keeping filesystems in synchronization

USES=		gmake

ALL_TARGET=	default
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's@/etc/init.d/ssyncd@\$$0@g' ${WRKSRC}/ssyncd.init
	@${REINPLACE_CMD} -e "s@/etc@${PREFIX}/etc@g;s@/usr/sbin@${PREFIX}/sbin@g;" \
		${WRKSRC}/ssyncd.init ${WRKSRC}/ssyncd.conf ${WRKSRC}/daemon.c \
		${WRKSRC}/ssync.man
	@${REINPLACE_CMD} -e "s@FLAGS=@FLAGS+=@g" -e "/CC=gcc/d" -e "/LD=gcc/d" \
		-e 's@$$(LD)@$$(CC)@' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssync ${STAGEDIR}${PREFIX}/bin/ssync
	${INSTALL_PROGRAM} ${WRKSRC}/ssyncd ${STAGEDIR}${PREFIX}/sbin/ssyncd
	${INSTALL_DATA} ${WRKSRC}/ssyncd.conf \
		${STAGEDIR}${PREFIX}/etc/ssyncd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ssyncd.work \
		${STAGEDIR}${PREFIX}/etc/ssyncd.work.sample
	${INSTALL_SCRIPT} ${WRKSRC}/ssyncd.init \
		${STAGEDIR}${PREFIX}/etc/rc.d/ssyncd.init
	${INSTALL_MAN} ${WRKSRC}/ssync.man \
		${STAGEDIR}${MANPREFIX}/man/man1/ssync.1

.include <bsd.port.mk>
