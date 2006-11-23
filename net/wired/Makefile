# New ports collection makefile for:	wired
# Date created:		2006-11-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	wired
PORTVERSION=	1.3.1
CATEGORIES=	net
MASTER_SITES=	http://www.zankasoftware.com/dist/

MAINTAINER=	trasz@pin.if.uz.zgora.pl
COMMENT=	Wired Server

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	wired.sh

MAN1=		hl2wired.1 wiredctl.1
MAN5=		wired.conf.5
MAN8=		wired.8

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/wired/etc/wired.conf ]; then \
		${CP} -p ${PREFIX}/wired/etc/wired.conf.sample ${PREFIX}/wired/etc/wired.conf ; \
	fi
	@if [ ! -f ${PREFIX}/wired/etc/resolv.conf ]; then \
		${CP} -p ${PREFIX}/wired/etc/resolv.conf.sample ${PREFIX}/wired/etc/resolv.conf ; \
	fi
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-deinstall:
	PKG_PREFIX=${PREFIX} ${SH} pkg-deinstall ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
