# New ports collection makefile for:	youbin
# http://www.agusa.nuie.nagoya-u.ac.jp/software/youbin/youbin-e.html
# Version required:		2.13
# Date created:			09 Aug 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.11 1998/08/03 09:09:48 ache Exp $
#

DISTNAME=	youbin-2.13
CATEGORIES=	mail
MASTER_SITES=	ftp://nuis.nuie.nagoya-u.ac.jp/info/nagoya-u/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/net/

MAINTAINER=	max@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
PREFIX=         ${LOCALBASE}
MTREE_FILE=	/etc/mtree/BSD.local.dist

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
		chmod 755 ${STARTUP_SCRIPT} ;				\
	fi
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
