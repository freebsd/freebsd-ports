# New ports collection makefile for:	youbin
# Date created:			09 Aug 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	youbin
PORTVERSION=	2.13
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nuie.nagoya-u.ac.jp/pub/nagoya-u/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/net/

MAINTAINER=	max@FreeBSD.org

USE_IMAKE=	yes
USE_XPM=	yes
#PREFIX?=	${LOCALBASE}
#MTREE_FILE?=	/etc/mtree/BSD.local.dist

MAN1=		youbin.1
MAN3=		youbin_sub.3
MAN8=		youbind.8

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/youbind.sh.sample

post-extract:
	(cd ${WRKSRC}; ${CP} -p Doc/*.man .)

pre-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGREQ} ${PKGNAME} BUILD

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Creating startup script '${STARTUP_SCRIPT}'" ;	\
		${SED} s:@PREFIX@:${PREFIX}: ${FILESDIR}/youbind.sh.sample \
		  > ${STARTUP_SCRIPT} ; \
		${CHMOD} 755 ${STARTUP_SCRIPT} ; \
	fi
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
