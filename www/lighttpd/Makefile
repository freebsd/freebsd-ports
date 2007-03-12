# New ports collection makefile for:		lighttpd
# Date created:					20 May 2004
# Whom:						k@123.org
#
# $FreeBSD$
#

PORTNAME=	lighttpd
PORTVERSION=	1.4.13
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/ \
		http://mirrors.cat.pdx.edu/lighttpd/

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A secure, fast, compliant, and very flexible Web Server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf:259 libtool:15
GNU_CONFIGURE=	yes
USE_GNOME=	lthack
USE_RC_SUBR=	lighttpd.sh
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/lighttpd
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		lighttpd.1 spawn-fcgi.1

OPTIONS=	BZIP2		"Enable Bzip2 support" off \
		CML		"Enable Cache Meta Language support" off \
		FAM		"Enable fam/gamin support" off \
		GDBM		"Enable gdbm storage support" off \
		IPV6		"Enable IPV6 support" on \
		MAGNET		"Enable magnet support" off \
		MEMCACHE	"Enable memcached storage support" off \
		MYSQL		"Enable MYSQL support" off \
		OPENLDAP	"Enable LDAP support" off \
		OPENSSL		"Enable SSL support" on \
		VALGRIND	"Enable valgrind support" off

.include <bsd.port.pre.mk>

# Default REQUIRE to rc.d script
_REQUIRE=	DAEMON

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl \
			--with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
.endif

.if defined(WITH_BZIP2)
LIB_DEPENDS+=		bz2:${PORTSDIR}/archivers/bzip2
CONFIGURE_ARGS+=	--with-bzip2
.endif

.if defined(WITH_CML)
USE_LUA=		yes
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
.endif

.if defined(WITH_FAM)
LIB_DEPENDS+=		fam:${PORTSDIR}/devel/fam
CONFIGURE_ARGS+=	--with-fam
CONFIGURE_ENV+=		FAM_CFLAGS="-I${LOCALBASE}/include" FAM_LIBS="-L${LOCALBASE}/lib"
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_MAGNET)
USE_LUA=		5.1+
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
.endif

.if defined(WITH_MEMCACHE)
CONFIGURE_ARGS+=	--with-memcache
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
_REQUIRE+=		mysql
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
_REQUIRE+=		slapd
.endif

.if defined(WITH_VALGRIND)
BUILD_DEPENDS+=		valgrind:${PORTSDIR}/devel/valgrind
RUN_DEPENDS+=		valgrind:${PORTSDIR}/devel/valgrind
CONFIGURE_ARGS+=	--with-valgrind
.endif

SUB_LIST+=		REQUIRE="${_REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -e 's|-D_XOPEN_SOURCE=600||' -e 's|-std=gnu99||' \
		${WRKSRC}/configure.in

post-install:
	@${INSTALL_DATA} ${FILESDIR}/lighttpd.conf.sample ${PREFIX}/etc
.if !exists(${PREFIX}/etc/lighttpd.conf)
	@${INSTALL_DATA} ${FILESDIR}/lighttpd.conf.sample ${PREFIX}/etc/lighttpd.conf
.endif
	@${LIBTOOL} --finish ${PREFIX}/lib

.include <bsd.port.post.mk>
