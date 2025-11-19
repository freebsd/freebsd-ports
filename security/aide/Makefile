PORTNAME=	aide
PORTVERSION=	0.19.2
CATEGORIES=	security
MASTER_SITES=	https://github.com/aide/aide/releases/download/v${PORTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File and directory integrity checker
WWW=		https://aide.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmhash.so:security/mhash \
		libpcre2-8.so:devel/pcre2

USES=		bison gmake localbase pkgconfig:build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX= ${PREFIX}/share
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--with-config_file=${PREFIX}/etc/aide.conf
CONFIGURE_ENV=	YACC="bison -y" \
		POSIX_ACL_CFLAGS="-I/usr/include" \
		POSIX_ACL_LIBS="-L/usr/lib" \
		MHASH_CFLAGS="-I${LOCALBASE}/include" \
		MHASH_LIBS="-L${LOCALBASE}/lib -lmhash"

LDFLAGS+=	-lpthread

OPTIONS_RADIO=	CRYPT
OPTIONS_DEFAULT=	GCRYPT
OPTIONS_RADIO_CRYPT=	GCRYPT NETTLE

GCRYPT_DESC=	use GNU crypto library
NETTLE_DESC=	use Nettle crypto library

GCRYPT_CONFIGURE_WITH=	gcrypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
NETTLE_CONFIGURE_WITH=	nettle
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle

SUB_FILES=	pkg-message

FLAVORS=	default without_acl
FLAVOR?=	${FLAVORS:[1]}

.if ${FLAVOR:U} != without_acl
CONFIGURE_ARGS+=--with-posix-acl \
		--with-e2fsattrs
LIB_DEPENDS+=	libe2p.so:filesystems/e2fsprogs-core
.endif

default_PKGNAMESUFFIX=
without_acl_PKGNAMESUFFIX=	-without_acl

post-install:
	${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${STAGEDIR}${PREFIX}/etc/aide.conf.sample
	${MKDIR} ${STAGEDIR}/var/db/aide/databases
	${CHMOD} 0700 ${STAGEDIR}/var/db/aide ${STAGEDIR}/var/db/aide/databases

.include <bsd.port.mk>
