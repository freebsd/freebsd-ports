# New ports collection makefile for:    gale
# Date created:         14 July 2000
# Whom:                 Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	gale
PORTVERSION=	0.99e
CATEGORIES=	net
MASTER_SITES=	http://www.mit.edu/afs/sipb/project/gale/src/ \
		# http://download.ofb.net/gale/ - original mastersite
DISTNAME=	${PORTNAME}-${PORTVERSION}gg

MAINTAINER=	peterh@sapros.com
COMMENT=	A secure instant messaging system

BUILD_DEPENDS=	${LOCALBASE}/lib/libgc.a:${PORTSDIR}/devel/boehm-gc
LIB_DEPENDS=	wwwcore.1:${PORTSDIR}/www/libwww \
		adns.1:${PORTSDIR}/dns/adns

USE_OPENSSL=	yes
USE_AUTOCONF_VER=213
USE_AUTOMAKE_VER=14
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-I${LOCALBASE}/include/w3c-libwww
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LIBTOOL_SHAREDIR}/libltdl

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
