# New ports collection makefile for:	wired
# Date created:		2006-11-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	wired
PORTVERSION=	1.3.3
CATEGORIES=	net
MASTER_SITES=	http://www.zankasoftware.com/dist/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Wired server

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${LOCALBASE}/lib" --includedir="${LOCALBASE}/include"
USE_GMAKE=	yes
USE_RC_SUBR=	wired.sh

MAN1=		wiredctl.1
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
	@if [ ! -f ${PREFIX}/wired/banlist ]; then \
		${CP} -p ${PREFIX}/wired/banlist.sample ${PREFIX}/wired/banlist ; \
	fi
	@if [ ! -f ${PREFIX}/wired/groups ]; then \
		${CP} -p ${PREFIX}/wired/groups.sample ${PREFIX}/wired/groups ; \
	fi
	@if [ ! -f ${PREFIX}/wired/news ]; then \
		${CP} -p ${PREFIX}/wired/news.sample ${PREFIX}/wired/news ; \
	fi
	@if [ ! -f ${PREFIX}/wired/users ]; then \
		${CP} -p ${PREFIX}/wired/users.sample ${PREFIX}/wired/users ; \
	fi
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-deinstall:
	${RM} -f ${PREFIX}/wired/etc/certificate.pem.sample
	PKG_PREFIX=${PREFIX} ${SH} pkg-deinstall ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
