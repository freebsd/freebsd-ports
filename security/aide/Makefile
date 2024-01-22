PORTNAME=	aide
PORTVERSION=	0.18.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/aide/aide/releases/download/v${PORTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File and directory integrity checker
WWW=		https://aide.github.io/

LIB_DEPENDS=	libmhash.so:security/mhash \
		libpcre2-8.so:devel/pcre2 \
		libe2p.so:sysutils/e2fsprogs-core

USES=		bison gmake localbase pkgconfig:build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX= ${PREFIX}/share
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--with-posix-acl \
		--with-e2fsattrs \
		--with-config_file=${PREFIX}/etc/aide.conf
CONFIGURE_ENV=	YACC="bison -y" \
		POSIX_ACL_CFLAGS="-I/usr/include/sys" \
		POSIX_ACL_LIBS="-L/usr/lib" \
		MHASH_CFLAGS="-I${LOCALBASE}/include" \
		MHASH_LIBS="-L${LOCALBASE}/lib -lmhash"

LDFLAGS+=	-lpthread

SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${STAGEDIR}${PREFIX}/etc/aide.conf.sample
	${MKDIR} ${STAGEDIR}/var/db/aide/databases
	${CHMOD} 0700 ${STAGEDIR}/var/db/aide ${STAGEDIR}/var/db/aide/databases

.include <bsd.port.mk>
