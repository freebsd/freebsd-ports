# $FreeBSD$

PORTNAME=	dynomite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.22
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic dynamo implementation for different k-v storage engines

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to configure: checking build system type... Invalid configuration 'aarch64-portbld-freebsd13.0': machine 'aarch64-portbld' not recognized
BROKEN_riscv64=		fails to configure: configure: error: /bin/sh config/config.sub riscv64-portbld-freebsd13.0 failed

USES=		autoreconf gmake libtool ssl
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Netflix

CFLAGS+=	-fcommon
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/dynomite-hash-tool \
		man/man8/dynomite.8.gz \
		sbin/dynomite \
		sbin/dynomite-test

.include <bsd.port.mk>
