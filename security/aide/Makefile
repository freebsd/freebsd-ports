PORTNAME=	aide
PORTVERSION=	0.18.6
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://github.com/aide/aide/releases/download/v${PORTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File and directory integrity checker
WWW=		https://aide.github.io/

LIB_DEPENDS=	libmhash.so:security/mhash \
		libpcre2-8.so:devel/pcre2

USES=		bison gmake localbase pkgconfig:build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX= ${PREFIX}/share
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--with-config_file=${PREFIX}/etc/aide.conf
CONFIGURE_ENV=	YACC="bison -y" \
		POSIX_ACL_CFLAGS="-I/usr/include/sys" \
		POSIX_ACL_LIBS="-L/usr/lib" \
		MHASH_CFLAGS="-I${LOCALBASE}/include" \
		MHASH_LIBS="-L${LOCALBASE}/lib -lmhash"

LDFLAGS+=	-lpthread

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
