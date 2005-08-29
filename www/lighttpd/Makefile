# New ports collection makefile for:		lighttpd
# Date created:					20 May 2004
# Whom:						k@123.org
#
# $FreeBSD$
#

PORTNAME=	lighttpd
PORTVERSION=	1.4.1
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/ \
		http://dl.fkb.wormulon.net/lighttpd/ \
		http://dl.kel.wormulon.net/lighttpd/

MAINTAINER=	hendrik@scholz.net
COMMENT=	A secure, fast, compliant, and very flexible Web Server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOCONF_VER=	259
USE_REINPLACE=		yes
USE_RC_SUBR=		lighttpd.sh
USE_LIBTOOL_VER=	15
USE_GNOME=		lthack
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS=-I${PREFIX}/include LIBS=-L${PREFIX}/lib
CONFIGURE_ARGS=		--libdir=${PREFIX}/lib/lighttpd

MAN1=		lighttpd.1 spawn-fcgi.1

OPTIONS=	OPENSSL		"Enable SSL support"	on \
		OPENLDAP	"Enable LDAP support"	off \
		MYSQL		"Enable MYSQL support"	off \
		IPV6		"Disable IPV6 support"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	@${INSTALL_DATA} ${FILESDIR}/lighttpd.conf.sample ${PREFIX}/etc/
	@${LIBTOOL} --finish ${PREFIX}/lib

.include <bsd.port.post.mk>
