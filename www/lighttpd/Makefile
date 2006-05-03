# New ports collection makefile for:		lighttpd
# Date created:					20 May 2004
# Whom:						k@123.org
#
# $FreeBSD$
#

PORTNAME=	lighttpd
PORTVERSION=	1.4.11
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/

MAINTAINER=	hendrik@scholz.net
COMMENT=	A secure, fast, compliant, and very flexible Web Server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf:259 libtool:15
GNU_CONFIGURE=	yes
USE_GNOME=	lthack
USE_RC_SUBR=	lighttpd.sh
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/lighttpd
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		lighttpd.1 spawn-fcgi.1

OPTIONS=	OPENSSL		"Enable SSL support"	on  \
		OPENLDAP	"Enable LDAP support"	off \
		MYSQL		"Enable MYSQL support"	off \
		IPV6		"Enable IPV6 support"	on \
		CML		"Enable Cache Meta Language support" off

.include <bsd.port.pre.mk>

# Default REQUIRE to rc.d script
_REQUIRE=	DAEMON

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl \
			--with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
_REQUIRE+=		slapd
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
_REQUIRE+=		mysql
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_CML)
LIB_DEPENDS+=		lua.5:${PORTSDIR}/lang/lua50
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L/${LOCALBASE}/lib
.endif

SUB_LIST+=		REQUIRE="${_REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -E -e 's|-D_XOPEN_SOURCE=600||' ${WRKSRC}/configure.in

post-install:
	@${INSTALL_DATA} ${FILESDIR}/lighttpd.conf.sample ${PREFIX}/etc
.if !exists(${PREFIX}/etc/lighttpd.conf)
	@${INSTALL_DATA} ${FILESDIR}/lighttpd.conf.sample ${PREFIX}/etc/lighttpd.conf
.endif
	@${LIBTOOL} --finish ${PREFIX}/lib

.include <bsd.port.post.mk>
