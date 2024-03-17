PORTNAME=	dynomite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.22
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic dynamo implementation for different k-v storage engines
WWW=		https://github.com/Netflix/dynomite

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to configure: checking build system type... Invalid configuration 'aarch64-portbld-freebsd13.0': machine 'aarch64-portbld' not recognized
BROKEN_armv6=		fails to build: invalid operands to binary expression ('char [buffer_size]' and 'unsigned int'), see https://github.com/Netflix/dynomite/issues/810
BROKEN_armv7=		fails to build: invalid operands to binary expression ('char [buffer_size]' and 'unsigned int'), see https://github.com/Netflix/dynomite/issues/810
BROKEN_riscv64=		fails to configure: configure: error: /bin/sh config/config.sub riscv64-portbld-freebsd13.0 failed

USES=		autoreconf gmake libtool ssl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

USE_GITHUB=	yes
GH_ACCOUNT=	Netflix

CFLAGS+=	-fcommon
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/dynomite-hash-tool \
		sbin/dynomite \
		sbin/dynomite-test \
		share/man/man8/dynomite.8.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
