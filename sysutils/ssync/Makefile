# New ports collection makefile for:	ssync
# Date created:		23 March 2002
# Whom:			Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
#
# $FreeBSD$
#

PORTNAME=	ssync
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mnmconsulting.org/ssync/ \
		ftp://ftp.netsw.org/system/tools/fileutils/install/ssync/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	A minimalistic tool for keeping filesystems in synchronization

ALL_TARGET=	default
USE_GMAKE=	yes
MAKEFILE=	makefile

MAN1=		ssync.1

post-patch:
	@${REINPLACE_CMD} -e 's@/etc/init.d/ssyncd@\$$0@g' ${WRKSRC}/ssyncd.init
	@${REINPLACE_CMD} -e "s@/etc@${PREFIX}/etc@g;s@/usr/sbin@${PREFIX}/sbin@g;" \
		${WRKSRC}/ssyncd.init ${WRKSRC}/ssyncd.conf ${WRKSRC}/daemon.c
	@${REINPLACE_CMD} -e "s@FLAGS=@FLAGS+=@g" ${WRKSRC}/makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ssync ${PREFIX}/bin/ssync
	@${INSTALL_PROGRAM} ${WRKSRC}/ssyncd ${PREFIX}/sbin/ssyncd
	@${INSTALL_DATA} ${WRKSRC}/ssyncd.conf ${PREFIX}/etc/ssyncd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/ssyncd.work ${PREFIX}/etc/ssyncd.work.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/ssyncd.init ${PREFIX}/etc/rc.d/ssyncd.init
	@${INSTALL_MAN} ${WRKSRC}/ssync.man ${MAN1PREFIX}/man/man1/ssync.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
