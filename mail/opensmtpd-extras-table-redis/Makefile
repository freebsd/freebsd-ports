# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-redis

COMMENT=	Redis table support for opensmtpd

LIB_DEPENDS=	libhiredis.so:databases/hiredis

PLIST_FILES=	libexec/opensmtpd/table-redis \
			man/man5/table-redis.5.gz

CONFIGURE_ARGS=	--with-table-redis
CONFIGURE_ENV=	REDIS_CONFIG=${LOCALBASE}/bin/pkgconf
CFLAGS+=	-I${LOCALBASE}/include/hiredis

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
