# New ports collection makefile for:	youbin
# http://www.agusa.nuie.nagoya-u.ac.jp/software/youbin/youbin-e.html
# Version required:		2.13
# Date created:			09 Aug 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	youbin-2.13
CATEGORIES=	mail
MASTER_SITES=	ftp://nuis.nuie.nagoya-u.ac.jp/info/nagoya-u/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/net/

MAINTAINER=	max@FreeBSD.ORG

FORBIDDEN=	see PR# 6180 about exploitable security hole

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
PREFIX=         ${LOCALBASE}
MTREE_FILE=	/etc/mtree/BSD.local.dist

MAN1=		youbin.1
MAN3=		youbin_sub.3
MAN8=		youbind.8

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/youbind.sh.sample

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		echo "Creating startup script '${STARTUP_SCRIPT}'" ;	\
		echo "#!/bin/sh" > ${STARTUP_SCRIPT} ;			\
		echo "if [ -f ${PREFIX}/sbin/youbind ]; then"		\
			>> ${STARTUP_SCRIPT} ;				\
		echo "    ${PREFIX}/sbin/youbind ; echo -n ' youbind'"	\
			>> ${STARTUP_SCRIPT} ;				\
		echo "fi" >> ${STARTUP_SCRIPT} ;			\
		${CHMOD} 755 ${STARTUP_SCRIPT} ;				\
	fi
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
