# ex:ts=8
# New ports collection makefile for:	ickle
# Date created:			Nov 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ickle
PORTVERSION=	0.1.2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	troff@paranoia.ru

LIB_DEPENDS=	gtkmm:${PORTSDIR}/x11-toolkits/gtk--

.if defined(WITH_CYRILLIC)
PATCHFILES+=	ickle-0.1.2.koi8.patch
PATCH_SITES+=	http://kva.paranoia.ru/~troff/
PATCH_DIST_STRIP=	-p1
.endif

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=	--with-sigc-prefix=${LOCALBASE} \
		--with-gtkmm-prefix=${X11BASE}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
